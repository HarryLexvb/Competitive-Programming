#include <bits/stdc++.h>

int main() {
    std::string s1, s2; // s1: name1, s2: name2
    while (getline(std::cin, s1)) {
        getline(std::cin, s2);
        int sum1 = 0, sum2 = 0;
        for (char i : s1) {
            if (isalpha(i)) {
                if (isupper(i)) {
                    sum1 += i - 'A' + 1;
                } else {
                    sum1 += i - 'a' + 1;
                }
            }
        }
        for (char i : s2) {
            if (isalpha(i)) {
                if (isupper(i)) {
                    sum2 += i - 'A' + 1;
                } else {
                    sum2 += i - 'a' + 1;
                }
            }
        }
        while (sum1 > 9) {
            int temp = sum1;
            sum1 = 0;
            while (temp) {
                sum1 += temp % 10;
                temp /= 10;
            }
        }
        while (sum2 > 9) {
            int temp = sum2;
            sum2 = 0;
            while (temp) {
                sum2 += temp % 10;
                temp /= 10;
            }
        }
        if (sum1 > sum2) {
            std::swap(sum1, sum2);
        }
        double ans = (double) sum1 / sum2 * 100;
        std::cout << std::fixed << std::setprecision(2) << ans << " %" << std::endl;
    }
    return 0;
}