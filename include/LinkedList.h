//
// Created by Christian Hong on 4/27/25.
//

#ifndef FIRSTPROJECT_LINKEDLIST_H
#define FIRSTPROJECT_LINKEDLIST_H
#include <string>

class LinkedList {
private:
    struct Node {
        std::string value;
        Node* next;
    };
    Node* head;

public:
     LinkedList();
     ~LinkedList();
     void insertAtFront(std::string v);
     void insertAtRear(std::string v);
     void deleteItem(std::string v);
     void printItems();
     bool search(std::string v);
};


#endif //FIRSTPROJECT_LINKEDLIST_H
