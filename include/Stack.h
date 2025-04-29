#ifndef FIRSTPROJECT_STACK_H
#define FIRSTPROJECT_STACK_H
#include <string>

class Stack {
private:
    struct Node {
        std::string value;
        Node* next;
    };
    Node* head;
public:
    Stack();
    ~Stack();
    void push(std::string v);
    std::string pop();
    std::string peek();
    void printStack();

};


#endif //FIRSTPROJECT_STACK_H
