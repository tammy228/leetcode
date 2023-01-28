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
 * Use two for loop, one for count size, and then take size/2 to get the result.
 */
ListNode* middleNode(ListNode* head) {
    int size = 0;
    ListNode* dummyHead = head;
    ListNode* result = head;
    while(dummyHead != nullptr){
        dummyHead = dummyHead->next;
        size++;
    }
    int mid = size % 2 == 0 ? size/2+1 : size/2;
    for(int i=0; i<mid; i++){
        result = result->next;
    }

    return result;
}