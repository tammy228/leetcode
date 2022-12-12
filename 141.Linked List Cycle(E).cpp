using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
 * My Solution
 * (Floyd's Tortoise and Hare Algo)
 * : It's an algo to check if there is a cycle exist
 * : Use to pointer one is -> slow, the other is -> faster, they will eventually meet if there is a cycle.
 *
 * Time: O(n)
 *
 * Space: O(1)
 */
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}