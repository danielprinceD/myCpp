#include <iostream>

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> id;
        int n = deck.size();
        for(int i=0;i<n;i++)id.push(i);
        sort(deck.begin() , deck.end());
        
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[id.front()] = deck[i];
            id.pop();
            if(!id.empty())
            {
                id.push(id.front());
                id.pop();
            }
        }
        return ans;

    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
