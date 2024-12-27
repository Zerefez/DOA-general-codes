
#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>

std::string find_most_frequent_word(const std::string& input) {
    std::unordered_map<std::string, int> word_count;
    std::string word;

    // Gennemgå strengen tegn for tegn
    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];

        // Ignorer kommaer og punktummer
        if (c == ',' || c == '.') {
            continue;
        }

        // Hvis det er et bogstav, tilføj det til ordet
        if (std::isalpha(c)) {
            word.push_back(std::tolower(c));  // Konverter til lille bogstav
        }
        else if (c == ' ' && !word.empty()) {
            // Når vi når et mellemrum og har et ord, tæller vi det
            word_count[word]++;
            word.clear();  // Tøm ordet for næste ord
        }
    }

    // Tæl det sidste ord, hvis det findesa
    if (!word.empty()) {
        word_count[word]++;
    }

    // Find det mest forekommende ord
    std::string most_frequent_word;
    int max_count = 0;

    for (const auto& entry : word_count) {
        if (entry.second > max_count) {
            most_frequent_word = entry.first;
            max_count = entry.second;
        }
    }

    return most_frequent_word;
}

int main() {
    std::string input = "The cattle were running back and forth, but there was no wolf to be seen, heard or smelled, so the shepherd decided to take a little nap in a bed of grass and early summer flowers. Soon he was awakened by a sound he had never heard before.";
    std::string result = find_most_frequent_word(input);
    std::cout << "The most frequent word is: " << result << std::endl;
    return 0;
}

