#include <bits/stdc++.h>

// datos
void ReadData(std::map<std::string, int>& m, int& n, int& q) {
    std::cin >> n >> q;
    while (n--) {
        std::string s;
        int integer, digit;
        char point;
        std::cin >> s >> integer >> point >> digit >> std::ws;
        m[s] = integer * 10 + digit;
    }
}

// evauar suposiciones
void EvaluateGuesses(const std::map<std::string, int>& m, int q) {
    for (int i = 1; i <= q; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream in(line);
        int right, left = 0;
        std::string s, op;

        while (in >> s >> op && op == "+")
            left += m.at(s);
        left += m.at(s);

        in >> right;
        right *= 10;

        if (op.find('=') != std::string::npos && left == right)
            std::cout << "Guess #" << i << " was correct.\n";
        else if (op.find('>') != std::string::npos && left > right)
            std::cout << "Guess #" << i << " was correct.\n";
        else if (op.find('<') != std::string::npos && left < right)
            std::cout << "Guess #" << i << " was correct.\n";
        else
            std::cout << "Guess #" << i << " was incorrect.\n";
    }
}

int main() {
    std::map<std::string, int> m;
    int n, q;

    ReadData(m, n, q);
    EvaluateGuesses(m, q);

    return 0;
}

