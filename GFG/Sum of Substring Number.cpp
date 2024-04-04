#include<bits/stdc++.h>
#define ll long long
using namespace std;


class Solution
{
    public:
    long long sumSubstrings(string s){
        ll prev = 0 , cur = 0  , ans = 0 , mod = 1e9+7;
        
        for(int i=0;i<s.size();i++)
        {
            cur = ( (i + 1)*(s[i]-'0') )  + prev * 10;
            cur %= mod;
            ans += cur;
            ans %= mod;
            prev = cur;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.maxDepth("(()()(daniel())");
}