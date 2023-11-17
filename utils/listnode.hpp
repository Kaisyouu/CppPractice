#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
    ListNode() : val(0), next(nullptr) {}
};

void Insert(ListNode* pHead, int val) {
    ListNode* pNode = new ListNode(val, nullptr);
    if (nullptr == pHead) {
        pHead = pNode;
        return;
    }
    ListNode* pCur = pHead;
    while (pCur->next != nullptr) {
        pCur = pCur->next;
    }
    pCur->next = pNode;
}

void Delete(ListNode* pHead, int val) {
    if (nullptr == pHead) return;
    ListNode* dummy = new ListNode(0, pHead);
    ListNode* pPre = dummy;
    ListNode* pCur = pHead;
    while (pCur->next != nullptr) {
        if (pCur->val == val) {
            pPre->next = pCur->next;
            pCur->next = nullptr;
            delete pCur;
            pCur = pPre->next;
        }
        else {
            pPre = pPre->next;
            pCur = pCur->next;
        }
    }
}

void Print(ListNode* pHead) {
    ListNode* pCur = pHead;
    while (pCur != nullptr) {
        std::cout << pCur->val << " ";
        pCur = pCur->next;
    }
    std::cout << std::endl;
}


#endif