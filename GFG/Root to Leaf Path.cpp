#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    void solver(Node* root , vector<int> leaf)
    {
        if(!root){return;}
            leaf.push_back(root->data);
        if(!root->left && !root->right ){
            ans.push_back(leaf);
        }
        solver(root->left , leaf);
        solver(root->right , leaf);
        return;
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<int> leaf;
        solver(root , leaf);
        return ans;
    }
};

int main()
{
}
