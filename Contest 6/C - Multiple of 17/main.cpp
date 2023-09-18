#include <iostream>
#include <string>

int CalculateModulus(const std::string& str) {
    int tmp = 0;
    for (char c : str) {
        tmp = tmp * 10 + (c - '0');
        tmp %= 17;
    }
    return tmp;
}

int main() {
    std::string str;
    while (std::getline(std::cin, str)) {
        if (str == "0")
            break;
        int result = CalculateModulus(str);
        std::cout << (result == 0) << std::endl;
    }
    return 0;
}