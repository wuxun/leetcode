#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedArrayToBST(vector<int> &num) {
    TreeNode *root = NULL;

    if (num.empty()) {
        return root;
    }

    if (num.size() == 1) {
        return new TreeNode(num[0]);
    }

    int mid = num.size() / 2;
    root = new TreeNode(num[mid]);

    vector<int>::const_iterator first = num.begin();
    vector<int>::const_iterator last = num.begin() + mid;

    vector<int> leftPart(first, last);
    root->left = sortedArrayToBST(leftPart);

    if (mid == num.size() - 1) {
        root->right = NULL;
    } else {
        first = num.begin() + mid + 1;
        last = num.end();
        vector<int> rightPart(first, last);
        root->right = sortedArrayToBST(rightPart);
    }

    return root;
}

int main(int argc, char *argv[])
{

    return 0;
}
