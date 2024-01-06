#include <bits/stdc++.h>
using namespace std;

vector<int> cuts;
int dp[1001][1001];

int solve(int l, int r) {
    if (l + 1 == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ans = INT_MAX;
    for (int i = 0; i < cuts.size(); i++) {
        if (cuts[i] > l && cuts[i] < r) {
            ans = min(ans, r - l + solve(l, cuts[i]) + solve(cuts[i], r));
        }
    }
    if (ans == INT_MAX) ans = 0;
    return dp[l][r] = ans;
}

int main() {
    int l, n;
    while (cin >> l && l) {
        cin >> n;
        cuts.clear();
        cuts.resize(n);
        for (int i = 0; i < n; i++) cin >> cuts[i];
        memset(dp, -1, sizeof(dp));
        cout << "The minimum cutting is " << solve(0, l) << ".\n";
    }
}