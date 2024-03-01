#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL)return false;
        
        int level = 0;
            int decreasing;
            int increasing;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> ans;
            increasing = 0;decreasing = 1e9;
            for(int i=0;i<size;i++)
            {
                TreeNode* top = q.front();
                q.pop();
                if(top->left!=NULL)q.push(top->left);
                if(top->right!=NULL)q.push(top->right);
                
                if(level%2!=0)
                {
                    if(top->val%2!=0 || decreasing <= top->val)return false;
                    decreasing = top->val;
                }
                if(level%2==0)
                {
                    if(top->val%2==0 || increasing >= top->val)return false;
                    increasing = top->val;
                }
                ans.push_back(top->val);
            }
            
            level++;
            
        }
        return true;
    }
};

int main()
{
    TreeNode* root = new TreeNode(5);
    TreeNode* l1 = new TreeNode(4 );
    TreeNode* r1 = new TreeNode(2 );
    TreeNode* r2 = new TreeNode(3 );
    TreeNode* r3 = new TreeNode(3 );
    TreeNode* r4 = new TreeNode(7 );
    
    root->left = l1;
    root->right = r1;
    
    l1->left = r2;
    l1->right = r3;
    
    r1->left = r4;
    
    Solution s;
    cout<<s.isEvenOddTree(root);
}
