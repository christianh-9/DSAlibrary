#include "../include/Queue.h"
#include <iostream>

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue() {
    while (front != nullptr) {
        dequeue();
    }
}

void Queue::enqueue(std::string v) {
    Node *newNode = new Node();
    newNode->value = v;
    newNode->next = nullptr;

    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

std::string Queue::dequeue() {
    if (front == nullptr) {
        return "";
    }
    std::string removeData = front->value;
    Node* temp = front;
    front = front->next;
    delete temp;

    if (front == nullptr) {
        rear = nullptr;
    }
    return removeData;
}

std::string Queue::peek() {
    if (front == nullptr) {
        return "";
    }
    return front->value;
}

void Queue::printQueue() {
    if (front == nullptr) {
        std::cout << "The queue is empty\n";
        return;
    }
    std::cout << "Tasks in queue:\n";
    Node* current = front;
    while (current != nullptr) {
        std::cout << current->value << '\n';
        current = current->next;
    }
}