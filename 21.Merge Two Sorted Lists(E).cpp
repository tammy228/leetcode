using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
 * My Solution
 * 1. use two pointers to iterate two list.
 * 2. compare the val of it, insert the smaller one to the new list(ans), and move the pointer to next
 *
 * Edge Case:
 * 1. two lists are empty -> return empty list.
 * 2. one of them is empty -> return another list.
 *
 */
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* tmp = dummyHead;

    while(list1 != nullptr && list2 != nullptr ){
        if(list1->val <= list2->val){
            tmp->next = list1;
            list1 = list1->next;
        }else{
            tmp->next = list2;
            list2 = list2->next;
        }
        tmp = tmp->next;
    }
    // Edge 1.
    if(list1)
        tmp->next = list1;
    else if(list2)
        tmp->next = list2;

    return dummyHead->next;
}