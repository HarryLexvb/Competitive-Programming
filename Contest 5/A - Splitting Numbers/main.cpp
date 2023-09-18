#include <iostream>

int main() {
    unsigned int n; // 32 bits

    while (std::cin >> n, n) {
        unsigned int a = 0, b = 0;

        bool addToA = true;
        unsigned int toAdd = 1;

        while (n) {
            if (n & 1) { // if the last bit is 1
                if (addToA)
                    a += toAdd;
                else
                    b += toAdd;

                addToA = !addToA;
            }

            toAdd *= 2;
            n /= 2;
        }

        std::cout << a << " " << b << std::endl;
    }

    return 0;
}
