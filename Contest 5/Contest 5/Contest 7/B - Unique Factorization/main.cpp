#include <iostream>
#include <vector>

typedef long long ll;

int k;
ll s;
std::vector<ll> v;
std::vector<std::vector<ll>> ans;

void recursion(ll n) {
    if (n <= 1) return;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            if (v.size() != 0 && v[v.size() - 1] > i) continue;
            v.push_back(i);
            recursion(n / i);
            v.push_back(s);
            ans.push_back(v);
            v.pop_back();
            v.pop_back();
        }
    }
    s = n;
}

int main() {
    ll n;
    while (std::cin >> n and n) {
        v.clear();
        k = 0;
        ans.clear();
        recursion(n);
        std::cout << ans.size() << std::endl;
        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < ans[i].size(); ++j) {
                if (j) std::cout << " ";
                std::cout << ans[i][j];
            }
            std::cout << std::endl;
        }
    }
}
