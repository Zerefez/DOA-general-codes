#pragma once

#include <vector>
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class Map
{
private:
	vector<Key> keys;
	vector<Value> values;

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
	keys = vector<Key>();
	values = vector<Value>();
}

template<typename Key, typename Value>
inline Map<Key, Value>::~Map()
{
	keys.clear();
	values.clear();
}

template<typename Key, typename Value>
inline void Map<Key, Value>::insert(const Key& key, const Value& value)
{
	keys.push_back(key);
	values.push_back(value);
}

template<typename Key, typename Value>
inline void Map<Key, Value>::remove(const Key& key)
{
	auto it = find(keys.begin(), keys.end(), key); // find the key
	if (it != keys.end()) // if key is found
	{
		int index = distance(keys.begin(), it); // get the index of the key
		keys.erase(keys.begin() + index); // remove the key
		values.erase(values.begin() + index); // remove the value
	}
	else
	{
		throw runtime_error("Key not found");
	}

	// Another way to remove the key and value
	/*
	* for (size_t i = 0; i < keys.size(); ++i)
	{
		if (keys[i] == key) // If key is found
		{
			keys.erase(keys.begin() + i); // Remove the key
			values.erase(values.begin() + i); // Remove the corresponding value
			return;
		}
	}
	throw runtime_error("Key not found");
	*/
}

template<typename Key, typename Value>
inline Value& Map<Key, Value>::operator[](const Key& key)
{
	auto it = find(keys.begin(), keys.end(), key); // find the key
	if (it != keys.end()) // if key is found
	{
		int index = distance(keys.begin(), it); // get the index of the key
		return values[index]; // return the value at the index
	}
	else
	{
		keys.push_back(key); // add the key
		values.push_back(Value()); // add a default value
		return values[values.size() - 1]; // return the default value
	}

	// Another way to implement the operator[]
	/*
	* for (size_t i = 0; i < keys.size(); ++i)
	{
		if (keys[i] == key) // If key is found
		{
			return values[i]; // Return the corresponding value
		}
	}

	// If key is not found, add the key and a default value
	keys.push_back(key);             // Add the new key
	values.push_back(Value());       // Add a default-constructed value
	return values.back();
	*/
}

template<typename Key, typename Value>
inline bool Map<Key, Value>::contains(const Key& key)
{
	auto it = find(keys.begin(), keys.end(), key);
	return it != keys.end();

	// Another way to implement the contains function
	/*
	for (const auto& k : keys) // Iterate through the keys
	{
		if (k == key) // If the key is found
		{
			return true; // Key exists
		}
	}
	return false; // Key not found
	*/
}

template<typename Key, typename Value>
inline void Map<Key, Value>::display()
{
	for (int i = 0; i < keys.size(); i++)
	{
		cout << keys[i] << " -> " << values[i] << endl;
	}
}