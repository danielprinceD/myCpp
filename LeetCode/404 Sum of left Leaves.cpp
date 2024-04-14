#include <iostream>
using namespace std;

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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode*, bool >> q;
        int sum = 0;
        q.push({root , false});
        while(!q.empty())
        {
            auto [top , isLeft] = q.front();
            q.pop();
            if(isLeft && !top->left && !top->right)
                sum+=top->val;
            if(top->left)q.push({top->left , true});
            if(top->right)q.push({top->right , false});
            
        }
        return sum;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
