#include <iostream>
#include <stack>

int main(){
    int n, i;
    std::cin >> n;
    std::cin.ignore();

    while(n > 0){
        std::string line;
        std::getline(std::cin, line);
        std::stack<char> stk;
        i = 0;
        while(line[i]){
            while(line[i] and (line[i] == '(' or line[i] == '[')) stk.push(line[i++]);
            if(!stk.empty() and line[i] == ')' and stk.top() == '(') stk.pop();
            else if(!stk.empty() and line[i] == ']' and stk.top() == '[') stk.pop();
            else break;
            ++i;
        }
        if(stk.empty() and line[i] == '\0') std::cout << "Yes\n";
        else std::cout << "No\n";
        --n;
    }
    return 0;
}