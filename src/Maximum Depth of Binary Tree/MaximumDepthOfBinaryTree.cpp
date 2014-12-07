#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max(int a, int b) {
    return a > b? a:b;
}

int maxDepth1(TreeNode *root){
    if (root == NULL) {
        return 0;
    } else {
        return 1 + max(maxDepth1(root->left), maxDepth1(root->right));
    }
}

struct Record {
    TreeNode *node;
    int depth;
};

int maxDepth2(TreeNode *root){
    if (root == NULL) return 0;

    std::queue<struct Record> records;
    struct Record tempRecord;

    int maxDepth = 1;
    struct Record firstRecord;
    firstRecord.node = root;
    firstRecord.depth = 1;

    records.push(firstRecord);

    while (!records.empty()) {
        struct Record parent = records.front();

        if (parent.node->left != NULL) {
            tempRecord.node = parent.node->left;
            tempRecord.depth = parent.depth + 1;
            records.push(tempRecord);
        }

        if (parent.node->right != NULL) {
            tempRecord.node = parent.node->right;
            tempRecord.depth = parent.depth + 1;
            records.push(tempRecord);
        }

        if (parent.node->left == NULL
            && parent.node->right == NULL){
            if (parent.depth > maxDepth) {
                maxDepth = parent.depth;
            }
        }

        records.pop();
    }

    return maxDepth;
}

int main(int argc, char** argv){
    struct TreeNode *node;
    struct TreeNode node1(1);
    struct TreeNode node2(2);
    struct TreeNode node3(3);
    node = &node1;
    node1.left = &node2;
    node2.right = &node3;

    cout<<maxDepth1(node)<<endl;
    cout<<maxDepth2(node)<<endl;
}
