#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int p, c;
        set<int> st;
        cin >> p >> c;
        int pp[p], cc[c];
        for (int i = 0; i < p; i++) {
            cin >> pp[i];
            st.insert(pp[i]);
        }
        for (int i = 0; i < c; i++) {
            cin >> cc[i];
            st.insert(cc[i]);
        }
        sort(pp, pp + p);
        sort(cc, cc + c);
        int res, n = INT_MAX;
        st.insert(0);
        for (set<int>::iterator i = st.begin(); i != st.end(); i++) {
            int a = lower_bound(cc, cc + c, (*i)) - cc;
            int b = p - (upper_bound(pp, pp + p, (*i)) - pp);

            if (a + b < n) {
                n = a + b;
                res = (*i);
            }
        }
        cout << res << " " << n << endl;
    }
    return 0;
}
