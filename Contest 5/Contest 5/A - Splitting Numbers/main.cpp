#include <bits/stdc++.h>

void solve(int n) {
    std::bitset<32> x(n), a, b;
    int c = 0;
    for (int i = 0; i < 32; ++i) {
        if (x[i]) {
            if (c & 1) b[i] = true;
            else a[i] = true;
            c++;
        }
    }
    std::cout << a.to_ulong() << " " << b.to_ulong() << std::endl;
}

int main() {
    int n;
    while (std::cin >> n) {
        if (n == 0)
            return 0;
        solve(n);
    }
}