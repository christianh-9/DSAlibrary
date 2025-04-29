//
// Created by Christian Hong on 4/27/25.
//

#ifndef FIRSTPROJECT_QUEUE_H
#define FIRSTPROJECT_QUEUE_H
#include <string>

class Queue {
private:
    struct Node {
        std::string value;
        Node* next;
    };
    Node* front;
    Node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(std::string v);
    std::string dequeue();
    std::string peek();
    void printQueue();
};


#endif //FIRSTPROJECT_QUEUE_H
