#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        vector<int> post_max(n,  0) , post_min(n, 0);
        post_max[n-1] = arr[n-1];
        post_min[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            post_max[i] = max(arr[i] , post_max[i+1]);
            post_min[i] = min(arr[i] , post_min[i+1]);
        }
        int ans = post_max[k] - post_min[k];
        int mini = arr[0] , maxi = arr[0];
        for(int i=1;i<n-k;i++)
        {
            ans = min(ans , max(post_max[i+k] , maxi) - min(post_min[i+k] , mini));
            mini = min(arr[i] , mini);
            maxi = max(arr[i] , maxi);
        }
        ans = min(ans , maxi-mini);
        return ans;
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
