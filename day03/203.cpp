//
// Created by unizh on 2023/12/29.
//
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val) {
    ListNode * dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;
    while(cur->next != NULL){
        if(cur->next->val != val){
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        else{
            cur = cur->next;
        }
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;
}