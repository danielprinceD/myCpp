#include <bits/stdc++.h>
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<pair<TreeNode* , int>> q;
        q.push({root , 1});
        if(depth == 1)
        {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            root = newNode;
            return root;
        }
        while(!q.empty())
        {
            auto [ node , deep ] = q.front();
            q.pop();
            if(deep+1 == depth)
            {
                TreeNode* left = new TreeNode(val);
                TreeNode* right = new TreeNode(val);
                left->left = node->left;     
                node->left = left;
                right->right = node->right;     
                node->right = right;
            }
            else 
            {
                if(node->left)
                    q.push({node->left , deep + 1});
                if(node->right)
                    q.push({node->right , deep + 1});
            }
        }

        return root;
    }
};

void print(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node = q.front();
        cout<<node->val<<" ";
        q.pop();
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
    }
    return;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* left1 = new TreeNode(2);
    TreeNode* right1 = new TreeNode(3);
    TreeNode* left2 = new TreeNode(4);
    root->left = left1;
    root->right = right1;
    left1->left = left2;
    Solution s;
    TreeNode*ans = s.addOneRow(root , 5 , 4);
    print(root);
    return 0;
}
