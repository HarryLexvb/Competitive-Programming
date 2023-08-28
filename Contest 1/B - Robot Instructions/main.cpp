#include <bits/stdc++.h>

int move[110];

int solution(const std::string &input, int i) {
    if (input[0] == 'S') { // S: same as previous
        int j;
        const std::string& str(input);
        std::string str2 = str.substr(str.find_last_of(' ') + 1);
        j = std::stoi(str2);
        move[i] = move[j - 1];
    } else {
        move[i] = (input[0] == 'L') ? -1 : 1; // L: -1, R: 1
    }
    return move[i];
}

int main() {
    int T, n; // T: test cases, n: number of instructions
    std::string arr_inp; // arr_inp: array of instructions

    std::cin >> T;
    while (T--) {
        std::cin >> n;
        std::cin.ignore(); // Ignore newline after n

        int i, pos = 0;
        for (i = 0; i < n; i++) {
            std::getline(std::cin, arr_inp);
            pos += solution(arr_inp, i);
        }

        std::cout << pos << std::endl;
    }

    return 0;
}