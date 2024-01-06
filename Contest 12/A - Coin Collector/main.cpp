#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3+2;
const ll inf = 1e14;
ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 1;
        ll x = a[0];
        a[n] = inf;
        for (int i = 1; i < n; i++) {
            if (x + a[i] < a[i + 1]) {
                ans++;
                x += a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}