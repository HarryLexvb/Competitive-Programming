#include <iostream>
#include <string>

const int mod = 1e9 + 7; // 10^9 + 7 = 1000000007 = 0x3b9aca07 = 1e9 + 7

std::string generatePalindrome(const std::string& a) {
    int len = a.length();
    std::string b(len, '0');  // Inicializamos b con la longitud de a y caracteres '0'.
    int l, r, mid, ans =0;
    l = r = mid = len / 2;

    if (len % 2 == 0) l--;

    for (int i = len; i >= 1; i--) {
        if (i % 2 != 0) {
            b[ans++] = a[mid];
            l = l - 1;
            r = r + 1;
        } else {
            if (a[l] > a[r]) {
                b[ans++] = a[l];
                mid = r;
            } else {
                b[ans++] = a[r];
                mid = l;
            }
        }
    }

    return b;
}

int calculateSum(const std::string& b) {
    int sum = 0;
    int t = 1;

    for (int i = b.length() - 1; i >= 0; i--) {
        if (i != b.length() - 1) t = (t * 2) % mod; // Usamos t *= 2 % mod para evitar desbordamientos.
        int temp = b[i] - '0';
        sum = (sum + temp * t) % mod;  // Usamos sum += temp * t % mod para evitar desbordamientos.
    }

    return sum;
}

int main() {
    int T;
    std::cin >> T;
    int ca = 1;

    while (T--) {
        std::string a;
        std::cin >> a;

        std::string palindrome = generatePalindrome(a);
        int sum = calculateSum(palindrome);

        std::cout << "Case #" << ca++ << ": " << sum << std::endl;
    }

    return 0;
}
