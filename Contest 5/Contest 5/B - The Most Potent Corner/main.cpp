#include <iostream>
#include <vector>

int calculateCornerPotency(const std::vector<unsigned char>& weights, int cornerIndex, int dimension) {
    int sum = 0;
    int mask = 1;

    for (int i = 0; i < dimension; ++i) {
        sum += weights[cornerIndex ^ mask];
        mask <<= 1;
    }

    return sum;
}

int findMaxPotencySum(const std::vector<unsigned char>& weights, int dimension) {
    int maxSum = -1;
    int cornerCount = 1 << dimension;

    for (int i = 0; i < cornerCount - 1; ++i) {
        int i_pow = calculateCornerPotency(weights, i, dimension);

        for (int mask = 1; mask < cornerCount; mask <<= 1) {
            int j = i ^ mask;
            int j_pow = calculateCornerPotency(weights, j, dimension);
            int currentSum = i_pow + j_pow;

            maxSum = std::max(maxSum, currentSum);
        }
    }

    return maxSum;
}

void processInput() {
    int d; // dimension
    int w; // weight

    while (std::cin >> d) {
        int cornerCount = 1 << d;
        std::vector<unsigned char> weights(cornerCount);

        for (int i = 0; i < cornerCount; ++i) {
            std::cin >> w;
            weights[i] = static_cast<unsigned char>(w);
        }

        int maxSum = findMaxPotencySum(weights, d);
        std::cout << maxSum << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    processInput();
    return 0;
}
