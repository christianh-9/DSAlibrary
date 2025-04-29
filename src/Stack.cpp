#include "../include/Stack.h"
#include <iostream>

Stack::Stack() {
    head = nullptr;
}

void Stack::printStack() {
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->value << "\n";
        temp = temp->next;
    }
    if (head == nullptr) {
        std::cout << "No books returned yet\n";
    }
}

std::string Stack::peek() {
    if (head == nullptr) {
        return "";
    }
    return head->value;
}

std::string Stack::pop() {
    if (head == nullptr) {
        return "";
    }
    std::string popped = head->value;
    Node *temp = head;
    head = head->next;
    delete temp;
    return popped;

}

void Stack::push(std::string v) {
    Node *newNode = new Node();
    newNode->value = v;
    newNode->next = head;
    head = newNode;
}

Stack::~Stack() {
    while (head != nullptr) {
        pop();
    }
}