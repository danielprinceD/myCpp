#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    
    vector<int> count(n , 1) , dp(n , 1);
    
    int maxim = 1;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                count[i] = count[j];
                
            }
            else if(arr[i] > arr[j] && dp[j] + 1 == dp[i])
            {
                count[i] += count[j];
            }
        }
        maxim = max(maxim , dp[i]);
    }
    
    for(int i=0;i<n;i++)cout<<dp[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)cout<<count[i]<<" ";
    
    int c = 0;
    
    for(int i=0;i<n;i++)
        if(maxim == dp[i])c+=count[i];
    
    return c;
}

int main()
{
    vector<int> v({1 , 5 ,4 , 3 ,2 , 6 ,7 , 10 , 8 , 9});
    cout<<findNumberOfLIS(v );
    return 0;
}