#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        float amt[amount+1];
        for(int i=1;i<=amount;i++)
        {
            amt[i] = numeric_limits<float>::infinity();
        }
        amt[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            for(auto &coin: coins)
            {
                if(coin <= i)
                {
                    amt[i] = min(amt[i],amt[i-coin]+1);
                }
            }
        }
        
        if(amt[amount] == numeric_limits<float>::infinity())
        {
            return -1;
        }
        
        return amt[amount];
        }
    
};
int main()
{
    vector <int > v  = {2,4};
    Solution s;
    cout<<s.coinChange(v,6);
    return 0;
}
