/*
剑指offer面试题7:重建二叉树
根据二叉树前序遍历结果与中序遍历结果，还原二叉树。
遍历结果中不含重复数字。
*/

#include "binary_tree.hpp"
#include <iostream>
#include <exception>

class Solution {
public:
    BinaryTreeNode* RebuildBinaryTree(int* preOrder, int* intOrder, int length) {
        if (preOrder == nullptr || intOrder == nullptr || length <= 0) return nullptr;
        return Construct(preOrder, preOrder+length-1,
                         intOrder, intOrder+length-1);
    }

private:
    BinaryTreeNode* Construct(int* startPreorder, int* endPreorder,
                              int* startIntorder, int* endIntorder) {
        // 初始化根节点为前序的第一个数字
        int rootValue = startPreorder[0];
        BinaryTreeNode* root = new BinaryTreeNode(rootValue);
        // 边界场景：只有一个节点
        if (startPreorder == endPreorder) {
            // 这个节点只能是根节点，否则报错
            if (startIntorder == endIntorder && *startPreorder == *startIntorder) return root;
            else throw std::runtime_error("Invalid input.");
        }
        // 在中序遍历中找到根节点的值
        int* rootIntorder = startIntorder;
        while (rootIntorder <= endIntorder && *rootIntorder != rootValue) {
            rootIntorder++;
        }
        if (rootIntorder == endIntorder && *rootIntorder != rootValue) {
            // 在中序遍历中没找到根节点的值
            throw std::runtime_error("Invalid input.");
        }
        int leftLength = rootIntorder - startIntorder;
        int* leftPreorderEnd = startPreorder + leftLength;
        if (leftLength > 0) {
            root->left = Construct(startPreorder+1, leftPreorderEnd,
                                   startIntorder, rootIntorder-1);
        }
        if (leftLength < endPreorder - startPreorder) {
            root->right = Construct(leftPreorderEnd+1, endPreorder,
                                    rootIntorder+1, endIntorder);
        }
        return root;
    }
};