#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> v;

bool pls(int all, int pl){
    if(pl == 5) return all == 23;
    int no = v[pl];
    return pls(all + no, pl + 1) || pls(all - no, pl + 1) || pls(all * no, pl + 1);
}

int main(){
    int a,b,c,d,e;
    while(cin >> a >> b >> c >> d >> e){
        if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0) break;
        v = {a, b, c, d, e};
        sort(v.begin(), v.end());
        bool ok = false;
        do{
            ok = pls(v[0], 1);
            if(ok)
                break;
        }while(next_permutation(v.begin(), v.end()));
        if(ok) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}