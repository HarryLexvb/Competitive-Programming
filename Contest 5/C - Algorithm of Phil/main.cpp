#include <iostream>
#include <string>

int main() {
    int T, cases = 0;
    std::cin >> T;
    while (T--) {
        std::string s;
        std::cin >> s;
        int n = s.length();
        int ret = 0;
        int p, q, r;
        const int mod = 1000000007;
        q = n / 2, p = q - 1;
        for (int i = 0, j = n & 1; i < n; ++i, j = !j) {
            if (j) {
                if (n - q > p)
                    r = (s[q] - '0'), q++;
                else
                    r = (s[p] - '0'), p--;
            } else {
                if (s[p] > s[q])
                    r = (s[p] - '0'), p--;
                else
                    r = (s[q] - '0'), q++;
            }
            ret = (ret << 1) + r;
            if (ret >= mod)
                ret %= mod;
        }
        std::cout << "Case #" << ++cases << ": " << ret << std::endl;
    }
    return 0;
}