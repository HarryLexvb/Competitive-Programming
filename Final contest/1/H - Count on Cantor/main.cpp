#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n){
        int a = 1, b = 1;
        int x = 0, z = 0;
        while(a < n){
            b++;
            a += b;
        }
        x = a - n + 1;
        z = b - x + 1;
        cout << "TERM " << n << " IS ";
        if(b % 2) cout << x << "/" << z << endl;
        else cout << z << "/" << x << endl;
    }
}