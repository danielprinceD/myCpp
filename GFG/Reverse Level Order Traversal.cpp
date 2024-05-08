#include <iostream>

vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*> q; vector<int> ans;
    q.push(root); ans.push_back(root->data);
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            Node* front = q.front();
            if(front->right){
                q.push(front->right);
                ans.push_back(front->right->data);
            }
            if(front->left)
            {
                q.push(front->left);
                ans.push_back(front->left->data);
            }
            q.pop();
        }
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int main()
{
    std::cout<<"Hello World";

    return 0;
}
