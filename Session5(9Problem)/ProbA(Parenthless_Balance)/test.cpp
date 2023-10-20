#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> ages = {
        {"Alice", 20},
        {"Bob", 25}
    };

    // Insert key-value pairs
    ages["Alice"] = 25;
    ages["Bob"] = 30;

    // Access values by key
    std::cout << "Alice's age: " << ages["Alice"] << std::endl;

    // Check if a key exists
    if (ages.find("Charlie") != ages.end()) {
        std::cout << "Charlie's age: " << ages["Charlie"] << std::endl;
    } else {
        std::cout << "Charlie not found in the map." << std::endl;
    }

    return 0;
}