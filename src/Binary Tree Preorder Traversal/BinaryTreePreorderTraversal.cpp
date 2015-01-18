#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorder;
vector<int> preorderTraversal1(TreeNode *root) {

    if (root == NULL) return preorder;

    preorder.push_back(root->val);
    preorderTraversal1(root->left);
    preorderTraversal1(root->right);
    return preorder;
}

vector<int> preorderTraversal2(TreeNode *root) {
    vector<int> pre;
    stack<TreeNode*> s;

    s.push(root);
    TreeNode* tmpNode = NULL;

    while (!s.empty()) {
        tmpNode = s.top();
        s.pop();

        if (tmpNode == NULL) continue;

        pre.push_back(tmpNode->val);
        s.push(tmpNode->right);
        s.push(tmpNode->left);
    }

    return pre;
}

int main(int argc, char *argv[])
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;

    vector<int> vec = preorderTraversal2(&a);
    preorderTraversal1(&a);

    for (int val : vec) {
        cout<<val<<" ";
    }
    cout<<endl;

    for (int val : preorder) {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
