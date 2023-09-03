#include <bits/stdc++.h>

/*
 - Harold Alejandro Villanueva Borda
 - Jan Gabriel Tupac Lazo
 */

int main() {
    int n;
    while (std::cin >> n and n) {
        std::vector<int> v(n); // vector with size n
        for (int i = 0; i < n; i++) {
            int c, p; // c = color, p = position
            std::cin >> c >> p;
            if (i + p < 0 or i + p >= n or v[i + p] != 0) v[0] = -1; // if the position is out of range or the position is already occupied
            else v[i + p] = c; // if the position is valid and is not occupied
        }
        if (v[0] == -1) { // if the first position is occupied
            std::cout << -1 << std::endl;
        } else { // if the first position is not occupied
            std::cout << v[0]; // print the first position
            for (int i = 1; i < n; ++i) // for the rest of the positions
                std::cout << " " << v[i]; // print the position
            std::cout << std::endl;
        }
    }
    return 0;
}
