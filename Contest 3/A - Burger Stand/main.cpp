#include <bits/stdc++.h>

int main() {
    int n_cases;
    std::cin >> n_cases;
    for (int cases = 1; cases <= n_cases; cases++) {
        std::string s;
        std::cin >> s;
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '-' and s[i + 1] != 'B' and s[i + 2] != 'B' and s[i + 1] != 'S' and s[i - 1] != 'S')
                ret++;
        }
        std::cout << "Case " << cases << ": " << ret << std::endl;
    }
    return 0;
}