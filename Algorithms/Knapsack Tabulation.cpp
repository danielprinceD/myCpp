#include <bits/stdc++.h> 
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n , vector<int> (maxWeight+1 , 0));
    
    for(int i=0;i<=maxWeight;i++)
        if(weight[0] <= i)
            dp[0][i] = value[0];
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            int notTake = dp[i-1][j];
            int take = -1e9;
            if(j - weight[i] > 0)
                take = value[i] + dp[i-1][j - weight[i]];
            dp[i][j] = max(notTake , take );
        }
    }
    return dp[n-1][maxWeight];
}

int main()
{
    vector<int> w = {3, 4, 5};
    vector<int> v = {30 , 50 , 60};
    cout<<knapsack(w , v , w.size() , 8);
}