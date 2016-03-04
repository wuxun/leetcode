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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        
        ListNode *oddCur = head;
        ListNode *evenCur = even;
        
        if (evenCur) {
            head = evenCur->next;
            while (head) {
                oddCur->next = head;
                oddCur = oddCur->next;
                
                evenCur->next = head->next;
                evenCur = evenCur->next;
                
                if (evenCur) {
                    head = evenCur->next;
                } else {
                    break;
                }
            }
        }
        
        oddCur->next = even;
        return odd;
    }
};
