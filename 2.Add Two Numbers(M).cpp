#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// My Solution: O(n)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* dummyHead = new ListNode(0);
    ListNode* tmp = dummyHead;
    while(l1 != nullptr || l2 != nullptr){
        int sum = 0;
        if(l1 != nullptr){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr){
            sum += l2->val;
            l2 = l2->next;
        }
        int tmpSum = (sum+carry) % 10;
        tmp->next = new ListNode(tmpSum);
        carry = (sum+carry)/10;
        tmp = tmp->next;
    }
    if(carry)
        tmp->next = new ListNode(carry);
    return dummyHead->next;
}
