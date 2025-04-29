//
// Created by Christian Hong on 4/28/25.
//

#ifndef FIRSTPROJECT_HASHTABLE_H
#define FIRSTPROJECT_HASHTABLE_H
#include <iostream>
#include <unordered_map>
#include <string>

class HashTable {
private:
    std::unordered_map<std::string, int> table;
public:
    HashTable();
    void addItem(const std::string& key, int value);
    bool searchItem(const std::string& key);
    void displayAll();
};


#endif //FIRSTPROJECT_HASHTABLE_H
