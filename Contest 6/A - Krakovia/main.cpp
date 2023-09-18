#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, m, ok=0;
    std::string s;
    while(std::cin >> n >> m and (n or m)){
        std::vector<int> base(1000, 0);
        for(int i = 0; i < n; ++i){
            std::cin >> s;
            std::reverse(s.begin(), s.end());
            for(int j = 0; j < s.size(); ++j)
                base[j] += s[j] - '0';
        }
        for(int i = 0; i < 1000; ++i){
            base[i+1] += base[i]/10;
            base[i] %= 10;
        }
        std::cout << "Bill #" << ++ok << " costs ";
        int i = 999;
        while(i >= 0 and base[i] == 0)
            --i;
        int j = i, temp = 0;
        std::vector<int> ans;
        for(; i >= 0; --i)
            std::cout << base[i];
        std::cout << ": each friend should pay ";
        for(; j >= 0; --j){
            temp = temp*10 + base[j];
            ans.push_back(temp/m);
            temp %= m;
        }
        int k = 0;
        while(k < ans.size() and ans[k] == 0)
            ++k;
        if(k == ans.size()){
            std::cout << 0 << std::endl << std::endl;
            continue;
        }
        for(; k < ans.size(); ++k)
            std::cout << ans[k];
        std::cout << std::endl << std::endl;
    }
    return 0;
}