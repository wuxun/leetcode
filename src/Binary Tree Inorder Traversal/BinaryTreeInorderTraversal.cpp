#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> v;
    stack<TreeNode*> s;

    if (root == NULL) return v;

    TreeNode *tmpNode = root;
    while (tmpNode != NULL) {
        s.push(tmpNode);
        tmpNode = tmpNode->left;
    }

    while (!s.empty()) {
        tmpNode = s.top();
        s.pop();

        v.push_back(tmpNode->val);

        if (tmpNode->right == NULL) {
            continue;
        }

        tmpNode = tmpNode->right;
        while (tmpNode != NULL) {
            s.push(tmpNode);
            tmpNode = tmpNode->left;
        }
    }

    return v;
}

// by haoel:https://github.com/haoel/leetcode/blob/master/src/binaryTreeInorderTraversal/binaryTreeInorderTraversal.cpp
// vector<int> inorderTraversal(TreeNode *root) {
//     vector<TreeNode*> stack;
//     vector<int> v;

//     while(stack.size()>0 || root!=NULL){
//         if (root!=NULL){
//             stack.push_back(root);
//             root = root->left;
//         }else{
//             if (stack.size()>0) {
//                 root = stack.back();
//                 stack.pop_back();
//                 v.push_back(root->val);
//                 root = root->right;
//             }
//         }
//     }
//     return v;
// }

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

    vector<int> vec = inorderTraversal(&a);

    for (int val : vec) {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
