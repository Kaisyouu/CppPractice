#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#pragma once
#include <iostream>
#include <queue>

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode() : val(0), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int _val = 0, BinaryTreeNode* _left = nullptr, BinaryTreeNode* _right = nullptr) :
        val(_val), left(_left), right(_right) {}
};

void PrintLevel(BinaryTreeNode* pRoot) {
    if (pRoot == nullptr) std::cout << "null" << std::endl;
    std::queue<BinaryTreeNode*> nodeToVisit;
    nodeToVisit.push(pRoot);
    while (!nodeToVisit.empty()) {
        BinaryTreeNode* cur = nodeToVisit.front();
        nodeToVisit.pop();
        std::cout << cur->val << " ";
        if (cur->left) nodeToVisit.push(cur->left);
        if (cur->right) nodeToVisit.push(cur->right);
    }
}

#endif