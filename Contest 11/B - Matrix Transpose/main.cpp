#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+2;
int a[N];
vector<pair<int,int>> v[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int i,j,n,m,k,x;
    while(cin >> n >> m){
        int mx = max(n,m);
        for(i = 1; i <= mx; i++) v[i].clear();
        for(i = 1; i <= n; i++){
            cin >> k;
            for(j = 0; j < k; j++) cin >> a[j];
            for(j = 0; j < k; j++){
                cin >> x;
                v[a[j]].emplace_back(i,x);
            }
        }
        for (i = 1; i <= m; i++) sort(v[i].begin(), v[i].end());
        cout << m << " " << n << "\n";
        for(i = 1; i <= m; i++){
            int sz = v[i].size();
            cout << sz;
            for(j = 0; j < sz; j++) cout << " " << v[i][j].first;
            cout << "\n";
            for(j = 0; j < sz; j++){
                if(j == 0) cout << v[i][j].second;
                else cout << " " << v[i][j].second;
            }
            cout << "\n";
        }
    }
    return 0;
}