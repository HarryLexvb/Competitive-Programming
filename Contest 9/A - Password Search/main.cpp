#include <bits/stdc++.h>

void solve(int n, std::string s){
    std::map<std::string, int> m;
    for (int i = 0; i < s.size() - n + 1; ++i) {
        std::string sub_s_actual = s.substr(i, n);
        if(m.count(sub_s_actual) <= 0)
            m.insert(std::pair<std::string, int>(sub_s_actual, 1));
        else if(m.count(sub_s_actual) > 0) m[sub_s_actual]++;
    }
    int max = 0;
    for(auto & it : m)
        if(it.second > max)
            max = it.second;

    for (auto & it : m)
        if(it.second == max)
            std::cout << it.first;
    std::cout << std::endl;
}

int main(){
    int n;
    std::string s;
    while(std::cin >> n>> s)
        solve(n, s);
}
