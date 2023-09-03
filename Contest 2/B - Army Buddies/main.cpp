#include <bits/stdc++.h>

/*
 - Harold Alejandro Villanueva Borda
 - Jan Gabriel Tupac Lazo
 */

int main() {
    int s, b; // s = number of soldiers, b = number of loss reports
    while (std::cin >> s >> b and s and b) {
        std::vector<int> left(s + 2), right(s + 2); // left[i] = left neighbor of soldier i, right[i] = right neighbor of soldier i
        for (int i = 0; i <= s + 1; ++i) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        while (b--) { // b loss reports
            int l, r;
            std::cin >> l >> r;
            if (left[l] < 1) std::cout << "* ";
            else std::cout << left[l] << " ";
            if (right[r] > s) std::cout << "*\n";
            else std::cout << right[r] << "\n";
            right[left[l]] = right[r];
            left[right[r]] = left[l];
        }
        std::cout << "-\n";
    }
    return 0;
}
