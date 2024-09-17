#include <iostream>
#include <unordered_map>
#include <string>

template <typename KeyType, typename ValueType>
class Dictionary {
private:
    std::unordered_map<KeyType, ValueType> hashTable;

public:
    // Function to add a key-value pair to the dictionary
    void insert(const KeyType& key, const ValueType& value) {
        hashTable[key] = value;  // Insert or update the key-value pair
    }

    // Function to remove a key-value pair from the dictionary
    void remove(const KeyType& key) {
        auto it = hashTable.find(key);
        if (it != hashTable.end()) {
            hashTable.erase(it);  // Remove the key-value pair if found
        }
        else {
            std::cout << "Key not found!\n";
        }
    }

    // Function to check if a key exists in the dictionary
    bool contains(const KeyType& key) const {
        return hashTable.find(key) != hashTable.end();
    }

    // Function to get the value associated with a key
    ValueType get(const KeyType& key) const {
        auto it = hashTable.find(key);
        if (it != hashTable.end()) {
            return it->second;  // Return the value if key is found
        }
        else {
            throw std::runtime_error("Key not found!");  // Throw an exception if key is not found
        }
    }

    // Function to get the size of the dictionary
    size_t size() const {
        return hashTable.size();
    }

    // Function to check if the dictionary is empty
    bool isEmpty() const {
        return hashTable.empty();
    }

    // Function to display all key-value pairs in the dictionary
    void display() const {
        if (hashTable.empty()) {
            std::cout << "Dictionary is empty!\n";
            return;
        }
        for (const auto& pair : hashTable) {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
    }
};

unsigned int hashFunction(const std::string& key) {
    unsigned int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    return sum;
}

unsigned int M;
unsigned int hashToArray(const std::string& key)
{
    return hashFunction(key) % M;
}

// Main function to demonstrate the functionality of the generic Dictionary ADT
int main() {
    // Dictionary with integer keys and string values
    Dictionary<int, std::string> intToStringDict;
    intToStringDict.insert(1, "One");
    intToStringDict.insert(2, "Two");
    intToStringDict.insert(2, "Twoish");
    intToStringDict.insert(3, "Three");

    std::cout << "Integer to String Dictionary:" << std::endl;
    intToStringDict.display();

    std::cout << "Contains key 2: " << (intToStringDict.contains(2) ? "Yes" : "No") << std::endl;
    std::cout << "Value for key 2: " << intToStringDict.get(2) << std::endl;

    // Remove an item and display again
    intToStringDict.remove(2);
    intToStringDict.display();

    // Dictionary with string keys and double values
    Dictionary<std::string, double> stringToDoubleDict;
    stringToDoubleDict.insert("pi", 3.14159);
    stringToDoubleDict.insert("e", 2.71828);

    std::cout << "\nString to Double Dictionary:" << std::endl;
    stringToDoubleDict.display();

    std::cout << "Value for key 'pi': " << stringToDoubleDict.get("pi") << std::endl;

    return 0;
}
