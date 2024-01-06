#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n and n != 0) {
        multiset<int> bills;
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                int x;
                cin >> x;
                bills.insert(x);
            }
            auto highest = --bills.end();
            auto lowest = bills.begin();
            total += (*highest - *lowest);
            bills.erase(highest);
            bills.erase(lowest);
        }
        cout << total << "\n";
    }

    return 0;
}