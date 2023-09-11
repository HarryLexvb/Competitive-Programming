#include <iostream>
#include <vector>
#include <algorithm>

int dfs(const std::vector<std::vector<int>>& g, int u, int p, int dep, int& place, int m, int s, int& ret) {
    //g: graph, u: current node, p: parent node, dep: depth, place: place, m: distance, s: VOD server node, ret: result
    int leaf = 0, pp = 0x3f3f3f3f;
    for (int v : g[u]) {
        if (v == p)
            continue;
        int p;
        int tmp = dfs(g, v, u, dep + 1, p, m, s, ret);
        pp = std::min(p, pp);
        leaf = std::max(leaf, tmp);
    }
    place = pp;
    if (leaf - dep + pp - dep <= m)
        leaf = 0;
    if (leaf == dep + m) {
        place = dep;
        ret += (u != s);
        leaf = 0;
    }
    return (g[u].size() == 1) ? dep : leaf;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n, m, s;
        std::cin >> n >> s >> m;
        std::vector<std::vector<int>> g(n + 1);
        for (int i = 1; i < n; ++i) {
            int x, y;
            std::cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int ret = 0;
        int foo;
        dfs(g, s, -1, 0, foo, m, s, ret);
        std::cout << ret << std::endl;
    }
    return 0;
}