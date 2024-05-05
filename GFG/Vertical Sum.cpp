#include <iostream>

class Solution{
  public:
    void preorder(Node* root , int level , map<int , int> &mp)
    {
        if(root==NULL)return;
        mp[level] += root->data;
        preorder(root->left , level-1 , mp);
        preorder(root->right , level+1 , mp);
    }
    vector <int> verticalSum(Node *root) {
       map<int,int> mp; vector<int> ans;
       preorder( root,0,mp);
       for(auto &i : mp)
        ans.push_back(i.second);
        return ans;
    }
};


int main()
{
    std::cout<<"Hello World";

    return 0;
}
