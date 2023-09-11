#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

int main() {
    int n;
    while(std::cin >> n){
        if (n == 0) break;
        std::vector<std::tuple<int,int,int,int>> a(n); // L, W, H, V
        for (int i = 0; i < n; ++i) {
            int l, w, h; // L: length, W: width, H: height
            std::cin >> l >> w >> h;
            a[i] = std::make_tuple(h, l*w*h, l,w); // h: height, l*w*h: volume, l: length, w: width
        }
        std::sort(a.begin(), a.end()); // sort by height
        std::cout << std::get<1>(a.back()) << std::endl; // print the volume of the ant with the highest downward acceleration
    }
}
