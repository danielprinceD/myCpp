#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &v){
    int n = v.size();
    vector<int> dp(n , 1) , hash(n);
    int maxim = 0 , max_ind = 0;
    for(int i=0;i<n;i++)
    {
        hash[i] = i;
        for(int prev=0;prev<i;prev++)        
            if(v[prev] < v[i] && dp[i] < 1 + dp[prev] )
            {
                dp[i] =  1 + dp[prev];
                if(maxim < dp[i])
                    max_ind = i;
                maxim = max( maxim , dp[i]);
                hash[i] = prev;
            }
    }
    
    vector<int> ans;
    ans.push_back(v[max_ind]);
    
    while(hash[max_ind] != max_ind)
    {
        max_ind = hash[max_ind];
        ans.push_back(v[max_ind]);
    }
    reverse(ans.begin() , ans.end());
    
    for(int &it : ans)
        cout<<it<<" ";
    return maxim;
}

int main()
{
    vector<int> v({5 , 4 , 11 , 1 , 16 , 8});
    cout<<LIS(v);
}