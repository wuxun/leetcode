#include <iostream>
#include <queue>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree1(TreeNode *p, TreeNode *q){
    if(!p && !q) return true;

    if(!p || !q) return false;

    return (p->val == q->val)
        && isSameTree1(p->left, q->left)
        && isSameTree1(p->right, q->right);
}

bool isSameTree2(TreeNode *p, TreeNode *q){
    queue<TreeNode*> queueP, queueQ;

    queueP.push(p);
    queueQ.push(q);
    while(!queueP.empty() && !queueQ.empty()){
        TreeNode *nodeP = queueP.front();
        queueP.pop();
        TreeNode *nodeQ = queueQ.front();
        queueQ.pop();

        if(!nodeP && !nodeQ) continue;

        if(!nodeP || !nodeQ) return false;

        if(nodeP->val != nodeQ->val) return false;

        queueP.push(nodeP->left);
        queueQ.push(nodeQ->left);

        queueP.push(nodeP->right);
        queueQ.push(nodeQ->right);
    }

    return true;
}

int main(int argc, char** argv){
    struct TreeNode node1(1);
    struct TreeNode node2(2);

    std::cout<<isSameTree1(&node1, &node2)<<std::endl;
    std::cout<<isSameTree2(&node1, &node2)<<std::endl;
}
