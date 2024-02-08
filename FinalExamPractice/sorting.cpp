#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Define the pairs
    std::pair<std::string, std::string> pair1 = {"2020-01-04", "00:15:07"};
    std::pair<std::string, std::string> pair2 = {"2020-01-04", "23:38:27"};
    std::pair<std::string, std::string> pair3 = {"2020-01-03", "17:35:07"};

    // Create a vector of pairs
    std::vector<std::pair<std::string, std::string>> pairs = {pair1, pair2, pair3};

    // Define a custom comparator function
    auto customComparator = [](const auto& a, const auto& b) {
        return a.first < b.first;
    };

    // Sort the vector using the custom comparator
    std::sort(pairs.begin(), pairs.end(), customComparator);

    // Display the sorted pairs
    for (const auto& pair : pairs) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}
