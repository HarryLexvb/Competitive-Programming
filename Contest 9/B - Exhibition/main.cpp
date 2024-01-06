#include <bits/stdc++.h>

void calculate(int k, int n, const std::vector<int>& counts) {
    int all = 0;
    for (int count : counts) all += count;

    std::cout << "Case " << k << ": ";
    if (all > 0) {
        for (int i = 0; i < n - 1; ++i)
            std::cout << std::fixed << std::setprecision(6) << (static_cast<double>(counts[i]) / all * 100) << "% ";
        std::cout << std::fixed << std::setprecision(6) << (static_cast<double>(counts[n - 1]) / all * 100) << "%" << std::endl;
    } else std::cout << std::endl;
}

int main() {
    int casee;
    std::cin >> casee;

    for (int k = 1; k <= casee; k++) {
        int n, m, x;
        std::cin >> n;
        std::map<int, int> TOid;
        std::vector<int> count(n, 0);

        for (int i = 0; i < n; i++) {
            std::cin >> m;

            while (m--) {
                std::cin >> x;

                if (TOid.count(x) == 0) {
                    count[i]++;
                    TOid[x] = i;
                } else if (TOid[x] >= 0 and TOid[x] != i) {
                    count[TOid[x]]--;
                    TOid[x] = -1;
                }
            }
        }
        calculate(k, n, count);
    }

    return 0;
}