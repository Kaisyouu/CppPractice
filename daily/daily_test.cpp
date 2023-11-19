#include "20231117.hpp"
#include <iostream>

int main() {
    Solution solution;
    int a[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int b[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode* pRoot = solution.RebuildBinaryTree(a, b, 8);
    PrintLevel(pRoot);
    return 0;
}