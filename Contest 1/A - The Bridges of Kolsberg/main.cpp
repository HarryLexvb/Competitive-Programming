#include <bits/stdc++.h>

struct city {
    std::string city_name; // city city_name
    std::string type_os; // operating system
    int trade_value{};  // trade_value value
};

int main() {
    int n_case;
    std::cin >> n_case;
    while (n_case--) {
        int n1, n2; // n1: N, n2: S
        std::cin >> n1;
        std::vector<city> N(n1); // N: North
        for (int i = 0; i < n1; i++) {
            std::cin >> N[i].city_name >> N[i].type_os >> N[i].trade_value;
        }
        std::cin >> n2;
        std::vector<city> S(n2); // S: South
        for (int i = 0; i < n2; i++) {
            std::cin >> S[i].city_name >> S[i].type_os >> S[i].trade_value;
        }
        std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (N[i - 1].type_os == S[j - 1].type_os) {
                    dp[i][j] = std::max(dp[i - 1][j - 1] + N[i - 1].trade_value + S[j - 1].trade_value, dp[i][j]);
                }
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
            }
        }
        std::cout << dp[n1][n2] << " ";
        int i = n1, j = n2;
        int ans = 0;
        while (i > 0 && j > 0) {
            if (dp[i][j] == dp[i - 1][j]) {
                --i;
            } else if (dp[i][j] == dp[i][j - 1]) {
                --j;
            } else {
                ans++;
                --i;
                --j;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}