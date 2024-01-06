#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        int cnt = 0;
        string s = "";
        while (n) {
            s += (n % 2) + '0';
            cnt += n % 2;
            n /= 2;
        }
        reverse(s.begin(), s.end());
        cout << "The parity of " << s << " is " << cnt << " (mod 2).\n";
    }
    return 0;
}