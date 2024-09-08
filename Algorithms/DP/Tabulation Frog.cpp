#include <bits/stdc++.h>
using namespace std;

int frogStairs(int step ,vector<int> height , vector<int> &dp)
{
    if(step <= 0)return 0;
    if(step == 1)return abs( height[step] - height[step-1] ) ;
    if(dp[step] != -1)return dp[step];
    
    int left = frogStairs(step-1  , height ,dp) + abs(height[step-1] - height[step]);
    int right = 1e9;
    if(step > 1)
        right =  frogStairs(step-2  , height , dp) + abs(height[step-2] - height[step]);
    return dp[step] = min( left , right); 
}

int main()
{
    vector<int> height = {10 , 20 , 30 , 10};
    vector<int> dp(height.size() , -1);
    
    int prev1 = 0 , prev2 = 0 ,cur = 0;
    for(int i=1;i<height.size();i++)
    {
        int left = prev1 + abs( height[i] - height[i-1] );
        int right = 1e9;
        if(i > 1)
            right = prev2 + abs( height[i] - height[i-2] );
        cur = min(left , right);
        prev2 = prev1;
        prev1 = cur;
    }
    
    cout<<cur;
    
    return 0;
}