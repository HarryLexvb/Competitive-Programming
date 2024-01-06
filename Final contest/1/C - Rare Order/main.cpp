#include <bits/stdc++.h>
using namespace std;

vector<int> adj[26];
bool visited[26];
stack<int> st;

void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
    st.push(u);
}

int main() {
    string s;
    vector<string> v;
    while (cin >> s) {
        if (s == "#") break;
        v.push_back(s);
    }
    for (int i = 0; i < v.size() - 1; i++) {
        string s1 = v[i];
        string s2 = v[i + 1];
        int j = 0;
        while (j < s1.size() && j < s2.size()) {
            if (s1[j] != s2[j]) {
                adj[s1[j] - 'A'].push_back(s2[j] - 'A');
                break;
            }
            j++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    while (!st.empty()) {
        cout << char(st.top() + 'A');
        st.pop();
    }
    cout << endl;
    return 0;
}