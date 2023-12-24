#include <iostream>
#include <sstream>

int countWords(const std::string& text) {
    std::stringstream ss(text);
    std::string word;
    int wordCount = 0;

    while (ss >> word) {
        wordCount++;
    }

    return wordCount;
}

int main() {
    std::string inputText;
    std::cout << "Enter the Text:" << std::endl;

    // Read the entire line, including spaces and tabs
    std::getline(std::cin, inputText);

    int numberOfWords = countWords(inputText);

    std::cout << "Number of words: " << numberOfWords << std::endl;

    return 0;
}
