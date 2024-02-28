#include <iostream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
void addElement(TreeNode*& root , int data)
{
    if(root==NULL)
    {
        TreeNode* newNode = new TreeNode(data);
        root = newNode;
    }
    else if(root->val > data && root->left ==NULL && root->right == NULL)
    {
        TreeNode* newNode = new TreeNode(data);
        root->left = newNode;
    }
    else if (root->val < data && root->left ==NULL && root->right == NULL)
    {
        TreeNode* newNode = new TreeNode(data);
        root->right = newNode;
    }
    else if (root->val < data) addElement(root->right,data);
    else if(root->val > data)addElement(root->left,data);
}
 
class Solution {
public:
    int maxDepth = -1 , leftval = 0;
    void dfs(TreeNode* &root , int depth)
    {
        if(root==NULL)return;
        if(depth > maxDepth)
        {
            maxDepth = depth;
            leftval = root->val;
        }
        dfs(root->left , depth + 1);
        dfs(root->right , depth + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root , 0);
        return leftval;
    }
};

int main()
{
    TreeNode* root=NULL;
    addElement(root , 1);
    addElement(root , 3);
    addElement(root , 6);
    TreeNode* two = new TreeNode(2);
    TreeNode* f = new TreeNode(4);
    TreeNode* fi = new TreeNode(5);
    TreeNode* se = new TreeNode(7);
    root->left = two;
    two->left = f;
    root->right->left = fi;
    fi->left = se;
    Solution s;
    cout<<s.findBottomLeftValue(root);
}
