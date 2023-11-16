#include "listnode.hpp"
#include <iostream>

void TestCase1() {
    ListNode* pHead = new ListNode(1, nullptr);
    Insert(pHead, 2);
    Insert(pHead, 3);
    Insert(pHead, 4);
    Insert(pHead, 5);
    Delete(pHead, 3);
    Print(pHead);
}


int main() {
    TestCase1();

    return 0;
}
