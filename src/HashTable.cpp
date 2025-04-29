#include "../include/HashTable.h"

HashTable::HashTable() {}

void HashTable::addItem(const std::string &key, int value) {
    table[key] = value;
    std::cout << key << " has been added/updated with the value " << value << '\n';
}

bool HashTable::searchItem(const std::string &key) {
    if (table.find(key) != table.end()) {
        std::cout << key << " exists with value: " << table[key] << '\n';
        return true;
    }
    else {
        std::cout << key << " was not found in the table\n";
        return false;
    }
}

void HashTable::displayAll() {
    if (table.empty()) {
        std::cout << "The hash table is empty\n";
        return;
    }
    std::cout << "Current items in the hash table:\n";
    for (const auto& pair : table) {
        std::cout << pair.first << " : " << pair.second << '\n';
    }
}