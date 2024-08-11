#include <bits/stdc++.h>
using namespace std;

// Buy Sell Stock with cooldown - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2 , 0) , prev1(2 , 0) , prev2(2 , 0) ;

        for(int i=n-1;i>=0;i--)
        {
                cur[1] = max(-prices[i] + prev1[0] , prev1[1]);
                cur[0] = max( prices[i] + prev2[1] , prev1[0]);
                
                prev2 = prev1;
                prev1 = cur;
        }
        return prev1[1];
    }
};

int main()
{
    
	return 0;
}