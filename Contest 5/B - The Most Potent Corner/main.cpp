#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

/*
- Harold Alejandro Villanueva
*/


int main() {
    int n; // dimension of the cube
    while (std::cin >> n) {
        std::vector<int> weights(pow(2, n)); // weights of the corners
        for (int i = 0; i < pow(2, n); ++i)
            std::cin >> weights[i];


        std::vector<int> potencies(pow(2, n)); // potencies of the corners
        for (int i = 0; i < pow(2, n); ++i) {
            for (int j = 0; j < n; ++j) {
                int neighbour = i ^ (1 << j);   // XOR for finding neighbours: 1^1 = 0, 0^1 = 1
                potencies[i] += weights[neighbour];
            }
        }
        int max_potency = 0; // max potency
        for (int i = 0; i < pow(2, n); ++i) { // find max potency
            for (int j = 0; j < n; ++j) {
                int neighbour = i ^ (1 << j);
                max_potency = std::max(max_potency, potencies[i] + potencies[neighbour]);
            }
        }
        std::cout << max_potency << std::endl;
    }
    return 0;
}