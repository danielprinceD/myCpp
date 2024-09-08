#include <bits/stdc++.h> 
using namespace std;

int combo(int i , int target , vector<int> &num)
{
    if(i == 0)
    {
        if(target % num[0] == 0)
            return target / num[0];
        else 
            return 1e9;
    }
    
    int notTake = combo(i-1 , target , num);
    int take = 1e9;
    if(num[i] <= target)
        take = 1 + combo(i , target - num[i] , num);
    return min(take , notTake);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n , vector<int>(x+1 , 1e9) );
    
    for(int target=0;target<=x;target++)
        if(target % num[0] == 0)
            dp[0][target] = target / num[0];
    
    for(int i=1;i<n;i++)
    {
        for(int target=0;target<=x;target++)
        {
            int notTake = dp[i-1][target];
            int take = 1e9;
            if(num[i] <= target)
                take = 1 + dp[i][target - num[i]];
                
            dp[i][target] = min(take , notTake);
        }
    }
    
    return dp[n-1][x];
}

int main()
{
    vector<int> v({1 , 2 , 3});
    cout<<minimumElements(v , 7);
}


// Space Optimized Code for Minimim Cost subarray


 int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    
    vector<int> prev(x+1 , 0);

    for(int target=0;target<=x;target++)
        if((target % num[0]) == 0)
            prev[target] = target / num[0];
        else prev[target] = 1e9;
    
    for(int i=1;i<n;i++)
    {
        vector<int> cur(x+1, 0);
        for(int target=0;target<=x;target++)
        {
            int notTake = prev[target];
            int take = 1e9;
            if(num[i] <= target)
                take = 1 + cur[target - num[i]];
            cur[target] = min(take , notTake);
        }
        prev = cur;
    }
    if(prev[x] >= 1e9)
        return -1;
    return prev[x];
}