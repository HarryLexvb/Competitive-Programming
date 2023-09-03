#include <bits/stdc++.h>

int main() {
    int n, q, x; // n: number of people, q: number of queries, x: the person
    std::vector<std::string> s(100 + 5); // s: the name of the person

    while(std::cin >> n) {
        for(int i = 1; i <= n; i++)
            std::cin >> s[i];

        std::cin >> q;

        while(q--) {
            std::cin >> x;
            if(s[x] != "?") // if the name of the person is not "?"
                std::cout << s[x] << std::endl;
            else { // if the name of the person is "?"
                int l, r, p;
                l = r = 0;
                p = x - 1;
                while(p > 0 and s[p] == "?") // find the left and right of the person
                    p--, l++;
                if(p <= 0)l = 0x3f3f3f; // if the person is at the leftmost, set l to a large number, 0x3f3f3f is a large number
                p = x + 1;
                while(p <= n && s[p] == "?") // find the right of the person
                    p++, r++;
                if(p > n)r = 0x3f3f3f; // if the person is at the rightmost, set r to a large number, 0x3f3f3f is a large number
                l++, r++;
                if(l == r) // if the person is in the middle of two people
                    std::cout << "middle of " << s[x - l] << " and " << s[x + r] << std::endl;
                else if(l < r) { // if the person is closer to the left
                    for(int j = 0; j < l; j++)
                        std::cout << "right of ";
                    std::cout << s[x - l] << std::endl;
                } else { // if the person is closer to the right
                    for(int j = 0; j < r; j++)
                        std::cout << "left of ";
                    std::cout << s[x + r] << std::endl;
                }
            }
        }
    }
    return 0;
}