#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> A, M, M_id, P;

void print(int end) {
    if (end < 0) return;
    print(P[end]);
    cout << A[end] << "\n";
}

void updateLIS(int num) {
    A.push_back(num);
    int pos = lower_bound(M.begin(), M.begin() + M.size(), num) - M.begin();
    if (pos == M.size()) {
        M.push_back(num);
        M_id.push_back(A.size() - 1);
    } else {
        M[pos] = num;
        M_id[pos] = A.size() - 1;
    }
    P.push_back(pos > 0 ? M_id[pos - 1] : -1);
}

int main() {
    int L = 0, L_end = 0;
    int num;
    while (cin >> num) {
        updateLIS(num);
        if (M.size() > L) {
            L = M.size();
            L_end = A.size() - 1;
        }
    }
    cout << L << "\n-\n";
    print(L_end);
    return 0;
}
