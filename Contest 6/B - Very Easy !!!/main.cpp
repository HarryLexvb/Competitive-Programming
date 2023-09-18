#include <iostream>

int main() {
    int N, A; // N: número de términos en la serie y A: valor de A
    while (std::cin >> N >> A) {
        int powers[200] = {}; // almacena los valores de la potencia k^i
        int current[200] = {1}; // almacena el valor actual de la serie
        for (int i = 0; i < N; i++) {
            for (int &val : current)
                val *= A;
            for (int index = 0; index < 199; index++) {
                current[index + 1] += current[index] / 10; // Llevar el acarreo
                current[index] %= 10; // Mantener solo el dígito de las unidades
            }
            for (int index = 0; index < 200; index++)
                powers[index] += current[index] * (i + 1); // Sumar a powers los términos de la serie
            for (int index = 0; index < 199; index++) {
                powers[index + 1] += powers[index] / 10; // Llevar el acarreo
                powers[index] %= 10; // Mantener solo el dígito de las unidades
            }
        }
        int total_digits = 199;
        while (total_digits > 0 and !powers[total_digits]) --total_digits; // Encontrar la cantidad de dígitos significativos
        for (int index = total_digits; index >= 0; --index)
            std::cout << powers[index];
        std::cout << std::endl;
    }
}
