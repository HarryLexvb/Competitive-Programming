#include <cmath>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <iomanip>

using namespace std;

const int MAX = 205;
const double INF = 1e9;

typedef pair<int, int> ii;
typedef pair<double, ii> dii;

int n;
int x[MAX], y[MAX];
double dist[MAX][MAX];

double euclidean(int i, int j) {
    return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

void floyd_warshall() {
    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for(int j = i + 1; j < n; j++) {
            dist[i][j] = dist[j][i] = euclidean(i, j);
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            if(dist[i][k] == INF) continue;
            for(int j = 0; j < n; j++) {
                if(dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
            }
        }
    }
}

int main() {
    int t = 1;
    while(cin >> n, n) {
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = INF;
            }
        }

        floyd_warshall();

        cout << "Scenario #" << t++ << "\n";
        cout << "Frog Distance = " << fixed << setprecision(3) << dist[0][1] << "\n\n";
    }
    return 0;
}