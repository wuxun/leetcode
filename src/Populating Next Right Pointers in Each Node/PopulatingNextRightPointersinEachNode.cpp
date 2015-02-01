#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    if (root != NULL && root->left != NULL && root->right != NULL) {
        root->left->next = root->right;
        if (root->next != NULL) {
            root->right->next = root->next->left;
        }

        connect(root->left);
        connect(root->right);
    }
}

void printTreeNext(TreeLinkNode *node) {
    if (node == NULL) return;

    cout<<"Node:"<<node->val<< " ";

    if (node->next != NULL) {
        cout<<"next value:"<<node->next->val<<endl;
    }
    cout<<endl;

    printTreeNext(node->left);
    printTreeNext(node->right);
}

int main(int argc, char *argv[])
{
    TreeLinkNode a(1);
    TreeLinkNode b(2);
    TreeLinkNode c(3);
    TreeLinkNode d(4);
    TreeLinkNode e(5);
    TreeLinkNode f(6);
    TreeLinkNode g(7);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    connect(&a);

    printTreeNext(&a);
    return 0;
}
