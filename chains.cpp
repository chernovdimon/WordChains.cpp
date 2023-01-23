#include <iostream>
#include <string>
#include <vector>
#include <random>

std::vector<std::string> words = { "word1", "word2", "word3", "word4", "word5" };
std::random_device rd;
std::mt19937 rng(rd());

int main() {
    std::cout << "Enter the number of word chains to generate: ";
    int numChains;
    std::cin >> numChains;

    for (int i = 0; i < numChains; i++) {
        std::cout << "Chain " << i + 1 << ": ";
        std::uniform_int_distribution<int> dist(0, words.size() - 1);
        std::string currentWord = words[dist(rng)];
        std::cout << currentWord;

        for (int j = 0; j < 5; j++) {
            std::string nextWord = words[dist(rng)];
            std::cout << " -> " << nextWord;
            currentWord = nextWord;
        }
        std::cout << std::endl;
    }
    return 0;
}
