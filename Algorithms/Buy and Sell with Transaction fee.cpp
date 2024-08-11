#include <bits/stdc++.h>
using namespace std;

// Buy Sell Stock with transaction fee - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices , int fee) {
        int n = prices.size();
        vector<int> cur(2 , 0) , prev(2 , 0);

        for(int i=n-1;i>=0;i--)
        {
                cur[1] = max(-prices[i] + prev[0] - fee , prev[1]);
                cur[0] = max( prices[i] + prev[1]  , prev[0]);
                
                prev = cur;
        }
        rezturn prev[1];
    }
};

int main()
{
    
	return 0;
}