//
// Created by Christian Hong on 4/27/25.
//

#include "../include/LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::printItems() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->value << "\n";
        temp = temp->next;
    }
    if (head == nullptr) {
        std::cout << "List is empty\n";
    }
}

void LinkedList::insertAtFront(std::string v) {
    Node* newNode = new Node();
    newNode->value = v;
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtRear(std::string v) {
    if (head == nullptr) {
        insertAtFront(v);
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        Node *newNode = new Node();
        newNode->value = v;
        newNode->next = nullptr;
        temp->next = newNode;
    }
}

void LinkedList::deleteItem(std::string v) {
    if (head == nullptr) {
        return;
    }
    if (head->value == v) {
        Node *destroy = head;
        head = destroy->next;
        delete destroy;
        return;
    }
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->next != nullptr && temp->next->value == v) {
            break;
        }
        temp = temp->next;
    }
    if (temp != nullptr) {
        Node *destroy = temp->next;
        temp->next = destroy->next;
        delete destroy;
    }
}

bool LinkedList::search(std::string v) {
    Node *current = head;
    while (current != nullptr) {
        if (current->value == v) {
            return true;
        }
        current = current->next;
    }
    return false;
}