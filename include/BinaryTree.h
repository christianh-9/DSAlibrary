//
// Created by Christian Hong on 4/27/25.
//

#ifndef FIRSTPROJECT_BINARYTREE_H
#define FIRSTPROJECT_BINARYTREE_H


class BinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    Node * root;

    Node* insert(Node* node, int value);
    bool search(Node* node, int value);
    void inOrder(Node* node);

public:
    BinaryTree();
    ~BinaryTree();
    void insert(int value);
    bool search(int value);
    void inOrder();
};


#endif //FIRSTPROJECT_BINARYTREE_H
