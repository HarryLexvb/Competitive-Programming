#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<int> adj[], int n, int src)
{
    vector<int> color(n, -1);
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u])
                return false;
        }
    }
    return true;
}

int main()
{
    int n, l;
    while (cin >> n && n)
    {
        cin >> l;
        vector<int> adj[n];
        for (int i = 0; i < l; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (bfs(adj, n, 0))
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}