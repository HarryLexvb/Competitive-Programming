#include <bits/stdc++.h>

void solve(int t){
    std::map<int, int > team;
    std::set<int> enteredQ;
    std::queue<int> teamQ;
    std::vector<std::queue<int>> indivQ(t);

    for (int i = 0; i < t; ++i) {
        int teamSize; std::cin >> teamSize;
        int tmp;
        for (int j = 0; j < teamSize; ++j) {
            std::cin >> tmp;
            team[tmp] = i;
        }
    }
    std::string cmd;
    int elem;
    while(std::cin >> cmd and cmd != "STOP"){
        if(cmd == "ENQUEUE"){
            std::cin >> elem;
            if(enteredQ.find(team[elem]) == enteredQ.end()){
                enteredQ.insert(team[elem]);
                teamQ.push(team[elem]);
                indivQ[team[elem]].push(elem);
            }else{
                indivQ[team[elem]].push(elem);
            }
        }
        else if(cmd == "DEQUEUE"){
            int fronTeam = teamQ.front();
            std::cout << indivQ[fronTeam].front() << '\n';
            indivQ[fronTeam].pop();
            if(indivQ[fronTeam].empty()){
                teamQ.pop();
                enteredQ.erase(fronTeam);
            }
        }
    }
}

int main (){
    int n = 0, t;
    while(std::cin >> t and t != 0){
        std::cout << "Scenario #" << n+1 << '\n';
        n++;
        solve(t);
        std::cout << '\n';
    }
}

