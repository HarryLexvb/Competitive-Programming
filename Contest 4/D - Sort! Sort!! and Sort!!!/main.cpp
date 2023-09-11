#include <vector>
#include <iostream>
#include <algorithm>

bool sortt(int a, int b, int m)
{
    if (a % m != b % m) return a % m < b % m;
    if (a & 1){
        if (b & 1) return a > b;
        return true;
    }
    if (b & 1) return false;
    return a < b;
}

int main()
{
    int n, m;

    while (std::cin >> n >> m, std::cout << n << ' ' << m << '\n', n){
        std::vector<int> numbers(n);

        for (int i = 0; i < n; ++i)
            std::cin >> numbers[i];

        std::sort(numbers.begin(), numbers.begin() + n, [m](int i, int j) {
            return sortt(i, j, m);
        });

        for (int i = 0; i < n; ++i)
            std::cout << numbers[i] << std::endl;
    }
}