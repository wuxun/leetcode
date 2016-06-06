/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>* ret = new vector<int>();
        if (!root) return *ret;
        queue<TreeNode*>* nodesLine = new queue<TreeNode*>();
        nodesLine->push(root);
        while(!nodesLine->empty()) {
            TreeNode* lastNode = nodesLine->back();
            ret->push_back(lastNode->val);
            TreeNode* temp = NULL;
            do {
                temp = nodesLine->front();
                if(temp->left) nodesLine->push(temp->left);
                if(temp->right) nodesLine->push(temp->right);
                nodesLine->pop();
            } while(temp != lastNode);
        }
        return *ret;
    }
};
