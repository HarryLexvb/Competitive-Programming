#include <bits/stdc++.h>
using namespace std;

int processQuery(int k, int v, map<int, vector<int>>& positions) {
    if (positions.find(v) != positions.end() && positions[v].size() >= k) {
        return positions[v][k - 1];
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<int> arr(n);
        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]].push_back(i + 1);
        }

        while (m--) {
            int k, v;
            cin >> k >> v;
            int result = processQuery(k, v, mp);
            cout << result << "\n";
        }
    }

    return 0;
}