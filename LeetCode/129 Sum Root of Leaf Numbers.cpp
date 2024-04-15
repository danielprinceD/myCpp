#include <iostream>

class Solution {
public:
    int solver(TreeNode *&root , int sum)
    {
        if(root==NULL)return 0;
        if(root->left == NULL && root->right == NULL) return sum*10 + root->val;
        return solver(root->left , sum*10 + root->val) + solver(root->right , sum*10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        return solver(root , 0 );
    }
};

int main()
{
}
