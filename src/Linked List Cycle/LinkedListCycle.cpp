#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == NULL) return false;

    ListNode *oneNodeATime = NULL;
    ListNode *twoNodesATime = NULL;

    oneNodeATime = head->next;
    if (oneNodeATime == NULL) return false;

    twoNodesATime = oneNodeATime->next;

    while (oneNodeATime != NULL && twoNodesATime != NULL) {
        oneNodeATime = oneNodeATime->next;
        if (twoNodesATime->next == NULL) return false;
        twoNodesATime = twoNodesATime->next->next;
        if (oneNodeATime == twoNodesATime) return true;
    }

    return false;
}

int main(int argc, char *argv[])
{
    ListNode a(1);
    ListNode b(1);
    ListNode c(1);
    ListNode d(1);
    a.next = &b;
    b.next = &c;
    c.next = &a;
    cout<<hasCycle(&a)<<endl;
    return 0;
}

