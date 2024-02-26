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
    bool traversal(TreeNode *root1 , TreeNode* root2)
    {
        if(root1==NULL && root2==NULL)return true;
        if(root1==NULL || root2==NULL)return false;
        if(root1->val!=root2->val)return false;
        if(traversal(root1->left , root2->left) && traversal(root1->right , root2->right))
            return true;
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traversal( p , q);
    }
};

int main()
{
    TreeNode*left = new TreeNode(2);
    TreeNode* head1 = new TreeNode(1 ,left ,NULL);
    
    TreeNode*right1 = new TreeNode(2);
    TreeNode* head2 = new TreeNode(1 ,NULL ,right1);
    Solution s;
    cout<<s.isSameTree(head1 , head2);
    return 0;
}
