using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * Time: O(N)
 *
 * Space: O(1)
 */
ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while(head){
        curr = head->next;
        head->next = prev;
        prev = head;
        head = curr;
    }
    return head;
}