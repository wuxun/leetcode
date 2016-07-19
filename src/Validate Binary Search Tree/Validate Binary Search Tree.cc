#include <iostream>
#include <stack>

using std::stack;
using std::cout;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* root, stack<int> &vals) {
    if (!root) return true;

    if (!helper(root->left, vals)) return false;

    if(vals.empty()) {
        vals.push(root->val);
    } else {
        if(!(vals.top() < root->val)) return false;
        vals.pop();
        vals.push(root->val);
    }

    return helper(root->right, vals);
}

bool isValidBST(TreeNode* root) {
    stack<int> vals;
    return helper(root, vals);
}

int main(int argc, char *argv[])
{
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);

    b->left = a;
    b->right = c;

    cout<<isValidBST(b);
    return 0;
}
