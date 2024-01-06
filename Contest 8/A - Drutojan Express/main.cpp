#include <bits/stdc++.h>

char name[5][50] = {"Ja", "Sam", "Sha", "Sid", "Tan"};

void simulateGame(int m, int n, int now, std::vector<int> *lis, int *v) {
    int p[5] = {0}, ti = 0;

    while (true) {
        if (ti + m >= n) {
            v[now] += n - ti;
            break;
        } else if (ti + m + 2 >= n) {
            v[now] += m;
            break;
        }
        ti += m + 2;

        int tmp = now;
        v[now] += m;
        now = lis[now][p[now]];
        p[tmp] = (1 + p[tmp]) % lis[tmp].size();
    }
}

void printResults(int *v) {
    for (int i = 0; i < 5; i++)
        std::cout << name[i] << " " << v[i] << std::endl;
}

int main() {
    int t, c = 1;
    std::map<std::string, int> M;

    for (int i = 0; i < 5; ++i) {
        M[name[i]] = i;
    }

    std::cin >> t;

    while (t--) {
        int m, n, now;
        char in[100];
        std::cin >> m >> n >> in;
        now = M[in];
        std::vector<int> lis[5];

        for (int i = 0; i < 5; i++) {
            int k;
            std::cin >> k;
            for (int j = 0; j < k; j++) {
                std::cin >> in;
                lis[i].push_back(M[in]);
            }
        }

        std::cout << "Case " << c++ << ":" << std::endl;
        int v[5] = {0};
        simulateGame(m, n, now, lis, v);
        printResults(v);
    }

    return 0;
}
