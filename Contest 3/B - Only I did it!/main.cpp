#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;
    for (int Case = 1; Case <= T; ++Case) {
        std::cout << "Case #" << Case << ":" << std::endl;
        std::vector<std::vector<int>> B(3);
        std::unordered_map<int, int> mark;

        for (int i = 0; i < 3; ++i) {
            int A;
            std::cin >> A;
            B[i].resize(A);
            for (int j = 0; j < A; ++j) {
                std::cin >> B[i][j];
                mark[B[i][j]]++;
            }
            std::sort(B[i].begin(), B[i].end());
        }

        int max = 0;
        std::vector<int> solve(3);

        for (int i = 0; i < 3; ++i) {
            int tmp = 0;
            for (int j : B[i]) {
                if (mark[j] == 1) {
                    tmp++;
                }
            }
            if (tmp > max) {
                max = tmp;
            }
            solve[i] = tmp;
        }

        for (int i = 0; i < 3; ++i) {
            if (solve[i] == max) {
                std::cout << i + 1 << " " << solve[i];
                for (int j : B[i]) {
                    if (mark[j] == 1) {
                        std::cout << " " << j;
                    }
                }
                std::cout << std::endl;
            }
        }
    }
    return 0;
}
