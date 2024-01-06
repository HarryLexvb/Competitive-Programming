#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, n;
    while (cin >> l && l) {
        cin >> n;
        vector<int> v(n + 2);
        v[0] = 0;
        v[n + 1] = l;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = 2; i <= n + 1; i++) {
            for (int j = 0; j <= n + 1 - i; j++) {
                int minn = INT_MAX;
                for (int k = j + 1; k < j + i; k++) {
                    minn = min(minn, dp[j][k] + dp[k][j + i]);
                }
                dp[j][j + i] = minn + v[j + i] - v[j];
            }
        }
        cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
    }
    return 0;
}