
#include <bits/stdc++.h>
using namespace std;

int knapsack(int i , int weights[] , int val[], int maxWt , int size , vector<vector<int>> &dp){
    if(i >= size)return 0;
    if(dp[i][maxWt] != -1) return dp[i][maxWt];
    int take = -1e9;

    if(weights[i] <= maxWt)
        take = val[i] + knapsack(i+1 , weights, val , maxWt - weights[i] ,  size, dp);
    return dp[i][maxWt] = max(take , knapsack(i+1 , weights, val, maxWt , size,dp ) );
}

int main()
{
    int weights[] = {3 , 4 , 5};
    int val[] = {30 , 50 , 60};
    int maxWt = 8;
    vector<vector<int>> dp(4 , vector<int>(8+1, -1));
    for(int i=weights[0];i<=maxWt;i++)dp[0][i] = val[0];
    
    
    vector<int> prev(maxWt + 1 , 0) , cur(maxWt + 1 , 0);

    for(int i=weights[0];i<=maxWt;i++)prev[i] = val[0];
    
    // Tabulation for Thief Sum
    for(int i=1;i<dp.size();i++)
    {
        int take = -1e9;
        for(int w=1;w<=maxWt;w++)
        {
            int notTake = dp[i-1][w];
            int take = -1e9;
            if(weights[i] <= w )
                take = val[i] + dp[i-1][w-weights[i]];

            dp[i][w] = max(take , notTake);
        }
    }
    
    // Knapsack for Thief Sum
    for(int i=1;i<dp.size();i++)
    {
        int take = -1e9;
        for(int w=1;w<=maxWt;w++)
        {
            int notTake = prev[w];
            int take = -1e9;
            if(weights[i] <= w )
                take = val[i] + prev[w-weights[i]];

            cur[w] = max(take , notTake);
        }
        prev = cur;
    }
    
    cout<<prev[maxWt];
    return 0;
}