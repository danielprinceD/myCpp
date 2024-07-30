#include <bits/stdc++.h>
using namespace std;


int ninjaTraining(int day , int last , vector<vector<int>> &v, vector<vector<int>> &dp)
{
    int n = v.size(),  m = v[0].size();
    int mini = -1e9;
    if(day == 0)
    {
        for(int task=0;task<m;task++)
            if(task != last)
                mini = max(mini , v[0][task]);
        return mini;
    }
    if(dp[day][last] != -1)return dp[day][last];
    
    for(int task=0;task<m;task++)
    {
        int count = -1e9;
        if(task != last)
            count = v[day][task] + ninjaTraining(day - 1 , task , v, dp);
        mini = max(count , mini);
    }
    return dp[day][last] = mini;
}


int main()
{   
    vector<vector<int>> v = {
        {10 , 50 , 1},
        {5 , 100 , 11},
    };
    vector<vector<int>> dp(v.size() , vector<int> (v[0].size()+1 , 0));
    
    dp[0][0] = max(v[0][1] , v[0][2] ) ; 
    dp[0][1] = max ( v[0][0] , v[0][2] );
    dp[0][2] = max ( v[0][0] , v[0][1] );
    dp[0][3] = max ( v[0][0] , max(v[0][1] , v[0][2]) );
    
    
    for(int day=1;day<v.size();day++)
    {
        for(int last=0;last<=v[0].size();last++)
        {
            int mini = -1e9;
            for(int task=0;task<v[0].size();task++)
            {
                if(task != last)
                {
                    int count = v[day][task] + dp[day-1][task];
                    mini = max(count , mini);   
                }
            }
            dp[day][last] = mini;
        }
    }
    cout<<dp[1][3];
    
}