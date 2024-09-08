#include <bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr, int n)
{
    int maxim = 1;
    vector<int> dp(n , 1) , dp2(n , 1);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(arr[i] > arr[j])
                dp[i] = max(dp[i] , 1 + dp[j]);
    
    
    
    for(int i=n-1;i>=0;i--)
        for(int j=n-1;j>i;j--)
            if(arr[i] > arr[j])
                dp2[i] = max(dp2[i] , 1 + dp2[j]);
    for(int i=0;i<n;i++)
        maxim = max(maxim , dp[i] + dp2[i] - 1);
    
    
    return maxim;
}

int main()
{
    vector<int> v({1 , 11 , 2 , 10 , 4 , 5 ,2 , 1});
    cout<<longestBitonicSubsequence(v , v.size());
    return 0;
}