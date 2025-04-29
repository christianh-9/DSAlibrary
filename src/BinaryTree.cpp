//
// Created by Christian Hong on 4/27/25.
//

#include "../include/BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {}

void BinaryTree::insert(int value) {
    root = insert(root, value);
}

BinaryTree::Node* BinaryTree::insert(Node *node, int value) {
    if (node == nullptr) {
        Node* newNode = new Node{value, nullptr, nullptr};
        return newNode;
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    }
    else if (value > node->data) {
        node->right = insert(node->right,value);
    }
    return node;
}

bool BinaryTree::search(int value) {
    return search(root, value);
}

bool BinaryTree::search(BinaryTree::Node *node, int value) {
    if (node == nullptr) {
        return false;
    }
    if (value == node->data) {
        return true;
    }
    else if (value < node->data) {
        return search(node->left, value);
    }
    else {
        return search(node->right, value);
    }
}

void BinaryTree::inOrder() {
    if (root == nullptr) {
        std::cout << "The tree is empty\n";
        return;
    }
    inOrder(root);
}

void BinaryTree::inOrder(BinaryTree::Node *node) {
    if (node != nullptr) {
        inOrder(node->left);
        std::cout << node->data << '\n';
        inOrder(node->right);
    }
}