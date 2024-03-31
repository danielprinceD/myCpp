#include <iostream>

class Solution {
public:
    vector<int > order;
    void solver(TreeNode* root)
    {
        if(root == NULL)return;
        order.push_back(root->val);
        if(root->left!=NULL)
            solver(root->left);
        if(root->right!=NULL)
            solver(root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        solver(root);
        return order;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
