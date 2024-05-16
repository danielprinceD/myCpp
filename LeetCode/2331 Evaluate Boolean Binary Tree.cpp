#include <iostream>

class Solution {
public:
    bool solver(TreeNode* &root)
    {
        if(!root)return 0;
        if(!root->left && !root->right) return root->val;
        if(root->val == 3)
            return solver(root->left) & solver(root->right);
        return solver(root->left) | solver(root->right);
    }
    bool evaluateTree(TreeNode* root) {
        return solver(root);
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
