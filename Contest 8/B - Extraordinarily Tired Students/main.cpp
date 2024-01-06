#include <iostream>
#include <vector>

int solveCase(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c) {
    int n = a.size();
    int sleep = 0;

    for (int i = 0; i < n; ++i) {
        if (c[i] > a[i])
            sleep++;
    }

    int time = 1;

    if (sleep == 0) {
        return time;
    } else {
        while (time < 10000) {
            int flag = 0;
            for (int i = 0; i < n; ++i) {
                c[i]++;
                if (c[i] == a[i] + b[i] + 1) {
                    c[i] = 1;
                    flag--;
                } else if (c[i] == a[i] + 1) {
                    if (sleep > n - sleep)
                        flag++;
                    else
                        c[i] = 1;
                }
            }
            sleep += flag;
            time++;
            if (sleep <= 0) break;
        }
    }

    if (time == 10000) {
        return -1;
    } else {
        return time;
    }
}

int main() {
    int n;
    int index = 1;
    while (std::cin >> n && n) {
        std::vector<int> a(n), b(n), c(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i] >> b[i] >> c[i];
        }

        int result = solveCase(a, b, c);

        std::cout << "Case " << index++ << ": " << result << std::endl;
    }
    return 0;
}