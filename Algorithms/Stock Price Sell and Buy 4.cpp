#include <bits/stdc++.h>
using namespace std;

// Stock Price with k Transaction - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2 , vector<int> (k+1 , 0)) , cur(2 , vector<int> (k+1 , 0));
        for(int i=n-1;i>=0;i--)
        {
            for(int canBuy=0;canBuy<=1;canBuy++)
            {
                for(int trans=1;trans<=k;trans++)
                {
                    int profit;
                    if(canBuy)
                        profit = -prices[i] + prev[0][trans];
                    else 
                        profit = prices[i] + prev[1][trans-1];
                    cur[canBuy][trans] = max(profit , prev[canBuy][trans]);
                }
            }
            prev = cur;
        }

        return prev[1][k];
    }
};

int main()
{
    
	return 0;
}