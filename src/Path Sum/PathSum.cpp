#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum1(TreeNode *root, int sum){
	if(root == NULL) return false;

	if(root->left == NULL && root->right == NULL){
		return sum == root->val;
	}

	if(root->left){
		if(hasPathSum(root->left, sum - root->val)){
			return true;
		}
	}

	if(root->right){
		if(hasPathSum(root->right, sum - root->val)){
			return true;
		}
	}

	return false;
}

int main(int argc, char** argv)
{

}
