#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *root) {
    while (root) {
        cout<<root->val;
        root = root->next;
    }
    cout<<endl;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

    ListNode *head = NULL;
    ListNode **current = NULL;

    head = l1;
    current = &head;

    printList(l1);
    printList(l2);

    while (l1 && l2) {
        if (l1->val < l2->val) {
            *current = l1;
            current = &((*current)->next);
            l1 = l1->next;
        } else {
            *current = l2;
            current = &((*current)->next);
            l2 = l2->next;
        }
    }

    if (l1) {
        *current = l1;
    } else {
        *current = l2;
    }

    return head;
}


int main(int argc, char *argv[])
{
    ListNode a1(1);
    ListNode b1(3);
    ListNode c1(5);
    ListNode d1(7);
    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;

    ListNode a2(2);
    ListNode b2(4);
    ListNode c2(6);
    ListNode d2(8);
    a2.next = &b2;
    b2.next = &c2;
    c2.next = &d2;

    printList(mergeTwoLists(NULL, &a2));
    cout<<endl;
    printList(mergeTwoLists(&a1, NULL));
    cout<<endl;
    printList(mergeTwoLists(&a1, &a2));
    return 0;
}
