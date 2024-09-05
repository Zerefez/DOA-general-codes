#pragma once
#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

int nextPrime(int n);

template <typename HashedObj>
class HashTable
{
public:
    explicit HashTable(int size = 101) : array(nextPrime(size))
    {
        makeEmpty();
    }
    void makeEmpty()
    {
        currentSize = 0;
        for (auto& entry : array)
            entry.info = EMPTY;
    }
    bool contains(const HashedObj& x) const
    {
        return isActive(findPos(x));
    }
    int size()
    {
        return currentSize;
    }
    bool insert(const HashedObj& x)
    {
        // Insert x as active
        int currentPos = findPosToInsert(x);
        if (isActive(currentPos)) {
            assert(array[currentPos].element == x);
            return false;
        }

        if (array[currentPos].info != DELETED)
            ++currentSize;

        array[currentPos] = std::move(x);
        array[currentPos].info = ACTIVE;

        // Rehash; see Section 5.5
        if (currentSize > array.size() / 2)
            rehash();

        return true;
    }
    bool insert(HashedObj&& x)
    {
        // Insert x as active
        int currentPos = findPosToInsert(x);
        if (isActive(currentPos)) {
            assert(array[currentPos].element == x);
            return false;
        }

        if (array[currentPos].info != DELETED)
            ++currentSize;

        array[currentPos] = std::move(x);
        array[currentPos].info = ACTIVE;

        // Rehash; see Section 5.5
        if (currentSize > array.size() / 2)
            rehash();

        return true;
    }
    bool remove(const HashedObj& x)
    {
        int currentPos = findPos(x);
        if (!isActive(currentPos))
            return false;

        array[currentPos].info = DELETED;
        return true;
    }
    enum EntryType { ACTIVE, EMPTY, DELETED };

private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry(const HashedObj& e = HashedObj{ }, EntryType i = EMPTY)
            : element{ e }, info{ i } { }

        HashEntry(HashedObj&& e, EntryType i = EMPTY)
            : element{ std::move(e) }, info{ i } { }
    };
    vector<HashEntry> array;
    int currentSize;
    bool isActive(int currentPos) const
    {
        return array[currentPos].info == ACTIVE;
    }
    int findPos(const HashedObj& x) const
    {
        int offset = 1;
        int currentPos = myhash(x);

        while (array[currentPos].info != EMPTY &&
            array[currentPos].element != x)
        {
            currentPos += offset;  // Compute ith probe
            offset += 2;
            if (currentPos >= array.size())
                currentPos -= array.size();
        }

        return currentPos;
    }
    int findPosToInsert(const HashedObj& x) const
    {
        int offset = 1;
        int currentPos = myhash(x);

        // We wish to stop looping when one of the following conditions are met:
        // 1. the element is empty
        // 2. the element is marked as deleted and thus available for reuse, or
        // 3. the element is active and matches the new element to be inserted (in which case no new insertion will be made)
        while (!(
            (array[currentPos].info == EMPTY) // 1
            || (array[currentPos].info == DELETED) // 2
            || (array[currentPos].info == ACTIVE
                && array[currentPos].element == x) // 3
            ))
        {
            currentPos += offset;  // Compute ith probe
            offset += 2;
            if (currentPos >= array.size())
                currentPos -= array.size();
        }

        return currentPos;
    }
    void rehash()
    {
        vector<HashEntry> oldArray = array;

        // Create new double-sized, empty table
        array.resize(nextPrime(2 * oldArray.size()));
        for (auto& entry : array)
            entry.info = EMPTY;

        // Copy table over
        currentSize = 0;
        for (auto& entry : oldArray)
            if (entry.info == ACTIVE)
                insert(std::move(entry.element));
    }
    size_t myhash(const HashedObj& x) const
    {
        static hash<HashedObj> hf;
        return hf(x) % array.size();
    }
};

#endif
