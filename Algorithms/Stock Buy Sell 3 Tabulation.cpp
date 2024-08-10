#include <iostream>
using namespace std;

// Recursion
 int findprofit(int i , int canBuy , int trans , vector<int> &p)
    {
        if(trans == 0 || i > p.size())return 0;
        int profit = 0;
        if(canBuy)
            profit = -p[i-1] + findprofit(i+1 , 0 , trans , p);
        else 
            profit = p[i-1] + findprofit(i+1 , 1 , trans - 1 , p);

        return max(findprofit(i+1 , canBuy , trans , p ) , profit);
    }

// Time and Space Optimized

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2 , vector<int> (3 , 0)) , cur(2 , vector<int>(3 , 0));

        for(int i=n-1;i>=0;i--)
        {
            for(int canBuy=0;canBuy<=1;canBuy++)
            {
                for(int trans=1;trans<=2;trans++)
                {
                    int profit;
                    if(canBuy)
                    profit = -prices[i] + prev[0][trans];
                    else 
                    profit = prices[i] + prev[1][trans-1];
                    cur[canBuy][trans] = max(prev[canBuy][trans], profit);
                }
                prev = cur;
            }
        }

        return prev[1][2];
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}