#include <iostream>
#include <vector>

void battle(std::vector<std::vector<int>>& g, int n) { // g: grid, n: number of heirs
    std::vector<std::vector<int>> next(g);
    int rowSize = g.size();
    int colSize = g[0].size();
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            int opp = (g[i][j] + 1) % n;
            if (i != 0 and g[i - 1][j] == opp)
                next[i - 1][j] = g[i][j];
            if (i + 1 != rowSize and g[i + 1][j] == opp)
                next[i + 1][j] = g[i][j];
            if (j != 0 and g[i][j - 1] == opp)
                next[i][j - 1] = g[i][j];
            if (j + 1 != colSize and g[i][j + 1] == opp)
                next[i][j + 1] = g[i][j];
        }
    }
    g = next;
}

int main() {
    int n, r, c, k;
    while (std::cin >> n >> r >> c >> k and n) { // n: number of heirs, r: row, c: column, k: number of battles
        std::vector<std::vector<int>> g(r, std::vector<int>(c));
        int v;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                std::cin >> v;
                g[i][j] = v;
            }
        }
        while (k--) {
            battle(g, n);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                std::cout << g[i][j] << (j + 1 == c ? "\n" : " ");
            }
        }
    }
    return 0;
}
