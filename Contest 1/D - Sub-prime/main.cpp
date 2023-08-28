#include <bits/stdc++.h>

int main() {
    int B, N; // B: number of banks, N: number of debentures
    while (std::cin >> B >> N) {
        if (B == 0 && N == 0) break;
        int arr[B];
        for (int i = 0; i < B; ++i) {
            std::cin >> *(arr + i);
        }
        int d, c, v; // debtor, creditor, value
        for (int i = 0; i < N; ++i) {
            std::cin >> d >> c >> v;
            *(arr + d - 1) -= v;
            *(arr + c - 1) += v;
        }
        bool flag = true; // el flag es para saber si todos los bancos tienen saldo positivo
        for (int i = 0; i < B; ++i) {
            if (*(arr + i) < 0) {
                flag = false;
                break;
            }
        }
        if (flag) std::cout << "S" << std::endl;
        else std::cout << "N" << std::endl;
    }
    return 0;
}