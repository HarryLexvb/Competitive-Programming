#include <iostream>
#include <stack>

int main(){
    std::stack<std::string> st; // stack of strings
    int n;
    std::cin >> n;
    std::string str, btr;
    while(n--){
        std::cin >> str;
        if(str == "Test"){
            if(!st.empty()) std::cout << st.top() << std::endl;
            else std::cout << "Not in a dream" << std::endl;
        }
        else if(str == "Sleep"){
            std::cin >> btr;
            st.push(btr);
        }
        else if(str == "Kick"){
            if(!st.empty()) st.pop();
        }
    }
    return 0;
}