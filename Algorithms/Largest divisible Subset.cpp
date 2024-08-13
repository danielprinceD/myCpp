#include <bits/stdc++.h>
using namespace std;


// Longest Divisible Subset

int main()
{
    vector<int> v({1 , 6 , 7 ,8 , 32 , 8 ,16});
    int n = v.size();
    vector<int> dp(n , 1);
    sort(v.begin() , v.end());
    int maxim = 1;
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(v[i] % v[j] == 0)
            {
                dp[i] = max(dp[i] , 1 + dp[j]);
                maxim = max(dp[i] , maxim);                
            }
                
    cout<<maxim;
    return 0;
}