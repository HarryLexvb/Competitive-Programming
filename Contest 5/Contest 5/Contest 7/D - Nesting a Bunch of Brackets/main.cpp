#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>

std::string corrige(std::string &st){
    std::string ans = "";
    st += " ";
    for (char &c : st) if(c == '/' or c == '\\') c = ' ';
    for (int i = 0; i < st.size()-1; i++) {
        if(st[i] == '(' and st[i+1] == '*') {
            ans += '/';
            i++;
        }
        else if(st[i] == '*' and st[i+1] == ')') {
            ans += '\\';
            i++;
        }
        else ans += st[i];
    }
    return ans;
}

void solve(std::string &st){
    std::map<char, char> contr;
    contr[']'] = '[';
    contr['\\'] = '/';
    contr['}'] = '{';
    contr['>'] = '<';
    contr[')'] = '(';

    std::stack<char> s;
    s.push('x');
    int ct = 0;
    for(int i = 0; i < st.size(); i++){
        char c = st[i];
        switch (c) {
            case '(': case '[': case '<': case '{': case '/':
                s.push(c);
                break;
            case ')': case ']': case '>': case '}': case '\\':
                char c2 = contr[c];
                if(s.top() != c2) {
                    std::cout << "NO " << i+1 << "\n"; return;
                }
                s.pop();
                break;
        }
    }
    if(s.size() != 1) std::cout << "NO " << st.size() + 1<< "\n";
    else std::cout << "YES\n";
}

int main(){
    std::string st;
    while(std::getline(std::cin, st)){
        st = corrige(st);
        solve(st);
    }
}


