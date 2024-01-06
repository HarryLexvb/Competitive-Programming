#include <iostream>
#include <algorithm>

using namespace std;

struct GasStation {
    int x, r;
};

bool compareGasStations(const GasStation& a, const GasStation& b) {
    return a.x - a.r < b.x - b.r;
}

int main() {
    int L, G;
    while (cin >> L >> G) {
        if (L == 0 && G == 0) break;

        GasStation* stations = new GasStation[G];  // Usar arreglo dinámico

        for (int i = 0; i < G; i++) {
            cin >> stations[i].x >> stations[i].r;
        }

        sort(stations, stations + G, compareGasStations);

        int cnt = 0;
        int idx = 0;
        int covered = 0;

        while (covered < L) {
            int maxCovered = covered;

            while (idx < G && stations[idx].x - stations[idx].r <= covered) {
                maxCovered = max(maxCovered, stations[idx].x + stations[idx].r);
                idx++;
            }

            if (maxCovered == covered) {
                cout << -1 << endl;
                break;
            }

            covered = maxCovered;
            cnt++;
        }

        if (covered >= L) {
            cout << G - cnt << endl;
        }

        delete[] stations;  // Liberar la memoria asignada
    }


}
