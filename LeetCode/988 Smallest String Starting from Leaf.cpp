#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string small = "";
    void solver(TreeNode* root , string &ans)
    {
        if(!root)return;
        ans += ('a' + root->val);
        if(!root->left && !root->right)
        {
            reverse(ans.begin() , ans.end());
            small = (small == "") ? ans : min(small , ans);
            reverse(ans.begin() , ans.end());
        }
        solver(root->left , ans);
        solver(root->right , ans);
        ans.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        solver(root , s);
        return  small;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
