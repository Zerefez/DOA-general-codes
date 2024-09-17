#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>

// Employee class as a custom key
class Employee {
public:
    std::string name;
    double salary;
    int seniority;  // Years of experience or seniority level

    // Constructor
    Employee(const std::string& name, double salary, int seniority)
        : name(name), salary(salary), seniority(seniority) {}

    // Equality operator
    bool operator==(const Employee& other) const {
        return name == other.name && salary == other.salary && seniority == other.seniority;
    }
};

// Custom hash function for the Employee class
struct EmployeeHash {
    std::size_t operator()(const Employee& employee) const {
        std::hash<std::string> hf;
        return hf(employee.name);
    }
};

// Generic Dictionary ADT using templates
template <typename KeyType, typename ValueType, typename Hash = std::hash<KeyType>>
class Dictionary {
private:
    std::unordered_map<KeyType, ValueType, Hash> hashTable;  // Internal hash table

public:
    // Insert key-value pair
    void insert(const KeyType& key, const ValueType& value) {
        hashTable[key] = value;
    }

    // Remove key-value pair
    void remove(const KeyType& key) {
        auto it = hashTable.find(key);
        if (it != hashTable.end()) {
            hashTable.erase(it);
        }
        else {
            std::cout << "Key not found!\n";
        }
    }

    // Check if key exists
    bool contains(const KeyType& key) const {
        return hashTable.find(key) != hashTable.end();
    }

    // Get value associated with key
    ValueType get(const KeyType& key) const {
        auto it = hashTable.find(key);
        if (it != hashTable.end()) {
            return it->second;
        }
        else {
            throw std::runtime_error("Key not found!");
        }
    }

    // Display all key-value pairs
    void display() const {
        for (const auto& pair : hashTable) {
            std::cout << "Key: " << pair.first.name << ", Salary: " << pair.first.salary
                << ", Seniority: " << pair.first.seniority
                << " | Value: " << pair.second << std::endl;
        }
    }
};

// Main function to demonstrate Dictionary with Employee class as key
int main() {
    // Create a dictionary with Employee as key and string (department) as value
    Dictionary<Employee, std::string, EmployeeHash> employeeDict;

    // Insert some Employee entries
    employeeDict.insert(Employee("Alice", 70000.0, 5), "Engineering");
    employeeDict.insert(Employee("Bob", 60000.0, 3), "Marketing");
    employeeDict.insert(Employee("Charlie", 80000.0, 10), "Management");

    // Display the dictionary
    std::cout << "Employee Department Dictionary:" << std::endl;
    employeeDict.display();

    // Check if a key exists
    Employee emp("Alice", 70000.0, 5);
    if (employeeDict.contains(emp)) {
        std::cout << "Alice's department: " << employeeDict.get(emp) << std::endl;
    }

    // Remove an Employee
    employeeDict.remove(Employee("Bob", 60000.0, 3));

    // Display after removal
    std::cout << "\nAfter removing Bob:" << std::endl;
    employeeDict.display();

    return 0;
}
