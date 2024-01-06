#include <bits/stdc++.h>
using namespace std;

void solve(string a, string b){
    int b_start = 0;
    for(auto m : b){
        b_start = max(b_start, m >= 'A' ? m - 'A' + 10 : m - '0');
    }

    vector<pair<int, long long>> b_base;
    for(int i = b_start + 1 == 1 ? 2 : b_start + 1; i <= 36; i++){
        long long num = 0;
        for(int j = 0; b[j]; j++){
            num += pow(i, (int)b.size()-j-1) * (b[j] >= 'A' ? b[j] - 'A' + 10 : b[j] - '0');
        }
        b_base.emplace_back(i, num);
    }

    int a_start = 0;
    for(auto m : a){
        a_start = max(a_start, m >= 'A' ? m - 'A' + 10 : m - '0');
    }

    for(int i = a_start +1 == 1 ? 2 : a_start + 1; i <= 36; i++){
        long long num = 0;
        for(int j = 0; a[j]; j++){
            num += pow(i, (int)a.size()-j-1) * (a[j] >= 'A' ? a[j] - 'A' + 10 : a[j] - '0');
        }
        for(auto m : b_base){
            if(num == m.second){
                cout << a << " (base " << i << ") = " << b << " (base " << m.first << ")\n";
                return;
            }
        }
    }
    cout << a << " is not equal to " << b << " in any base 2..36\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    while(cin >> a >> b){
        solve(a, b);
    }
}