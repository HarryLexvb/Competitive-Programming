#include <iostream>

int main(){
    int n, m, s;
    while(std::cin >> n >> m){
        if(4*n < m) s = 10*n -2*m;
        else if(3*n < 2*m) s = 8*n - 4*m;
        else if(2*n < 3*m) s = 6*n - 6*m;
        else if(n < 4*m) s = 3*n - 9*m;
        else s = -1;

        if(s < 0) std::cout << "Deficit" << std::endl;
        else std::cout << s << std::endl;
    }
    return 0;
}