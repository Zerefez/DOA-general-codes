#pragma once

#include <vector>
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class Map
{
private:
    vector<pair<Key, Value>> data;

public:
    Map();
    ~Map();
    void insert(const Key& key, const Value& value);
    void remove(const Key& key);
    Value& operator[](const Key& key);
    bool contains(const Key& key);
    void display();
};

template<typename Key, typename Value>
inline Map<Key, Value>::Map()
{
    data = vector<pair<Key, Value>>();
}

template<typename Key, typename Value>
inline Map<Key, Value>::~Map()
{
    data.clear();
}

template<typename Key, typename Value>
inline void Map<Key, Value>::insert(const Key& key, const Value& value)
{
    for (auto& pair : data) { // Iterate through key-value pairs
        if (pair.first == key) { // If key exists
            pair.second = value;  // Update value if key exists
            return;
        }
    }
    data.push_back(make_pair(key, value));  // Add new key-value pair
}

template<typename Key, typename Value>
inline void Map<Key, Value>::remove(const Key& key)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        if (data[i].first == key)  // If key is found
        {
            data.erase(data.begin() + i);  // Remove the key-value pair
            return;
        }
    }
    throw runtime_error("Key not found");
}

template<typename Key, typename Value>
inline Value& Map<Key, Value>::operator[](const Key& key)
{
    for (auto& pair : data) {
        if (pair.first == key) {
            return pair.second;  // Return value if key exists
        }
    }
    // If key not found, insert a default value
    data.push_back(make_pair(key, Value()));
    return data.back().second;
}

template<typename Key, typename Value>
inline bool Map<Key, Value>::contains(const Key& key)
{
    for (const auto& pair : data)
    {
        if (pair.first == key)
        {
            return true;  // Key exists
        }
    }
    return false;  // Key not found
}

template<typename Key, typename Value>
inline void Map<Key, Value>::display()
{
    for (const auto& pair : data)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }
}
