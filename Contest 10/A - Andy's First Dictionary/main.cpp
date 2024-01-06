#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string toLowerCase(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

int main() {
    std::vector<std::string> words;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::string word;
        for (char c : line) {
            if (isalpha(c)) {
                word += c;
            } else if (!word.empty()) {
                words.push_back(toLowerCase(word));
                word = "";
            }
        }
        if (!word.empty()) {
            words.push_back(toLowerCase(word));
        }
    }

    std::sort(words.begin(), words.end());

    std::string previousWord = "";
    for (const std::string& word : words) {
        if (word != previousWord) {
            std::cout << word << std::endl;
            previousWord = word;
        }
    }

    return 0;
}
