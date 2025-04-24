#include "Hashtable.h"
#include<functional>

HashTable::HashTable() : table(Default_Capacity) {}

int HashTable::hashFucntion(const std::string& key) const {
    std::hash<std::string> hasher;
    return hasher(key) % table.size();
}

bool HashTable::insert(const std::string& hash, const std::string& original) {
    int idx = hashFucntion(hash);
    for (const auto& pair : table[idx]){
        // This will check if the hash already exists
        if (pair.first == hash) return false;
    }
    table[idx].emplace_back(hash, original);
    return true;
}

bool HashTable::lookup(const std::string& hash, std::string& original) const {
    int idx = hashFucntion(hash);
    for (const auto& pair : table[idx]) {
        if (pair.first == hash) {
            original = pair.second;
            return true;
        }
    }
    return false;
}
