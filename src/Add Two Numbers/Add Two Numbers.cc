#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* n1 = l1;
    ListNode* n2 = l2;
    int add = 0;
    ListNode* ret = NULL;
    ListNode* root = NULL;


    while (n1 || n2) {
        int sum = 0;

        if (n1) {
            sum += n1->val;
        }

        if (n2) {
            sum += n2->val;
        }

        sum += add;

        if (sum >= 10) {
            add = sum / 10;
        } else {
            add = 0;
        }
        ListNode* tmpNode = new ListNode(sum % 10);
        if (ret) {
            ret->next = tmpNode;
            ret = ret->next;
        } else {
            ret = tmpNode;
            root = ret;
        }

        if (n1) {
            n1 = n1->next;
        }

        if (n2) {
            n2 = n2->next;
        }
    }

    if (add != 0) {
        ListNode* tmpNode = new ListNode(add);
        ret->next = tmpNode;
    }

    return root;
}

int main(int argc, char *argv[])
{
    ListNode a(1);
    ListNode b(5);
    ListNode c(6);
    a.next = &b;
    b.next = &c;

    ListNode d(2);
    ListNode e(8);
    ListNode f(9);
    d.next = &e;
    e.next = &f;

    ListNode* ret = addTwoNumbers(&a, &d);
    while (ret) {
        cout<<ret->val<<" ";
        ret = ret->next;
    }
    cout<<endl;
    return 0;
}
