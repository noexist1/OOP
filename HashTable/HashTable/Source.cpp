#include "hash_table.h"
#include <stdexcept>

uint64_t hash_function(const Key& key, size_t cap)
{
    size_t hash = 5381;
    for (auto& it : key)
        hash = ((hash << 5) + hash) + int(it);
    return hash % cap;
}

HashTable::HashTable(size_t capacity) 
{
    HashTable::cap = capacity;
    HashTable::size_prop = 0;
    HashTable::data.resize(HashTable::cap);
}
HashTable::~HashTable() 
{
    HashTable::data.clear();
    HashTable::data.resize(0);
}

HashTable::HashTable(const HashTable& b) {
    *this = b;
}

HashTable::HashTable(HashTable&& b)  noexcept 
{
    *this = b;
    delete& b;
}

HashTable& HashTable::operator=(const HashTable& b) 
{
    HashTable::cap = b.cap;
    HashTable::data.clear();
    HashTable::data.resize(HashTable::cap);
    HashTable::size_prop = 0;
    for (int i = 0; i < b.cap; i++) 
    {
        Datalist blist = b.data[i];
        auto itb = blist.begin();
        while (itb != blist.end()) 
        {
            (*this).insert(itb->first, { itb->second.age, itb->second.weight });
            itb++;
        }
    }
    return *this;
}

HashTable& HashTable::operator=(HashTable&& b)  noexcept 
{
    *this = b;
    delete& b;
    return *this;
}