/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *newHead = head;
        ListNode *leftHead = head->next;
        newHead->next = NULL;
        while (leftHead) {
            ListNode *temp = leftHead->next;
            leftHead->next = newHead;
            newHead = leftHead;
            leftHead = temp;
        }

        return newHead;
    }
};
