#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<string>
#include<vector>
#include<list>

class HashTable {
private:
    static const int Default_Capacity = 1000;
    std::vector<std::list<std::pair<std::string, std::string>>> table;

    int hashFucntion(const std::string& key) const;

public:
    HashTable();
    bool insert(const std::string& hash, const std::string& original);
    bool lookup(const std::string& hash, std::string& original) const;
};

#endif 
