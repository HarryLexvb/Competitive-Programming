#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cout << "Case #" << caseNo << ":" << endl;

        int L, R, S;
        cin >> L >> R >> S;

        unordered_map<int, set<int>> chocolates;
        set<int> allChocolates;

        // Leju
        for (int i = 0; i < L; i++) {
            int type;
            cin >> type;
            chocolates[type].insert(1);
            allChocolates.insert(type);
        }

        // Rony
        for (int i = 0; i < R; i++) {
            int type;
            cin >> type;
            chocolates[type].insert(2);
            allChocolates.insert(type);
        }

        // Sujon
        for (int i = 0; i < S; i++) {
            int type;
            cin >> type;
            chocolates[type].insert(3);
            allChocolates.insert(type);
        }

        int uniqueLeju = 0, uniqueRony = 0, uniqueSujon = 0;
        int commonLejuRony = 0, commonLejuSujon = 0, commonRonySujon = 0;

        for (int type : allChocolates) {
            if (chocolates[type].size() == 1) {
                if (chocolates[type].count(1)) uniqueLeju++;
                if (chocolates[type].count(2)) uniqueRony++;
                if (chocolates[type].count(3)) uniqueSujon++;
            } else if (chocolates[type].size() == 2) {
                if (chocolates[type].count(1) and chocolates[type].count(2)) commonLejuRony++;
                if (chocolates[type].count(1) and chocolates[type].count(3)) commonLejuSujon++;
                if (chocolates[type].count(2) and chocolates[type].count(3)) commonRonySujon++;
            }
        }

        cout << uniqueLeju << " " << commonRonySujon << endl;
        cout << uniqueRony << " " << commonLejuSujon << endl;
        cout << uniqueSujon << " " << commonLejuRony << endl;
    }

    return 0;
}
