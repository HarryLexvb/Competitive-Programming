#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    int coins[] = {1, 5, 10, 25, 50};
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = coins[i]; j <= n; j++) {
            dp[j] += dp[j-coins[i]];
        }
    }
    cout << dp[n] << endl;
}

int main() {
    int n;
    while (cin >> n) {
        solve(n);
    }
}