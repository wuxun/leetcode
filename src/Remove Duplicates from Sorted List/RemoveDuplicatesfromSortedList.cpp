#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head) {
    ListNode *tmp = head;
    while (tmp) {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

ListNode *deleteDuplicates(ListNode *head) {

    printList(head);

    while (head && head->next) {
        if (head->val == head->next->val) {
            ListNode *dup = head->next;
            head->next = head->next->next;
            delete dup;
        } else {
            head = head->next;
        }
    }

    return head;
}



int main(int argc, char *argv[])
{
    return 0;
}
