#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector<std::vector<ll>> matrix;

void solve(){
    int n, m, M; // number of local merchants among all n traders
    std::cin >> n >> m >> M;

    std::vector<int> num(n + 1, 0);
    matrix c(n + 1, std::vector<ll>(n + 1, 0));
    matrix dp(n + 1, std::vector<ll>(n - m + 1, 0));

    for(int i = 0; i <= n; ++i){
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
    }

    for(int i = 0; i < m; ++i){
        int a, b; // m pairs of integers, a: position i-th in the queue, b: favorite position
        std::cin >> a >> b;
        num[b]++;
    }

    int flag = 0, s = 0;
    for (int i = n; i >=1 ; --i) {
        s += num[i];
        if (s > n - i + 1) flag = 1;
    }

    if (flag) {
        std::cout << "NO" << std::endl;
        return;
    }

    dp[0][n - m] = 1;
    s = 0;

    for(int i = 0; i < n; ++i){
        s += num[i + 1];
        int t1 = n - i - 1;
        for (int j = 0; j <= n - m; ++j) {
            if (!dp[i][j]) continue;
            for (int k = std::max(0, i + 1 - (n - m - j + s)); k <= j; ++k) {
                dp[i + 1][j - k] += dp[i][j] * c[j][k];
                dp[i + 1][j - k] %= M;
            }
        }
    }

    std::cout << "YES " << dp[n][0] << std::endl;
}

int main(){
    int n_cases;
    std::cin >> n_cases;

    for(int i = 1; i <= n_cases; ++i)
        solve();

    return 0;
}
