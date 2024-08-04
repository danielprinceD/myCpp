#include <bits/stdc++.h>
using namespace std;

bool isSubsequenceTarget(int i , int target , vector<int> &v)
{
    if(target == 0)return 1;
    if(i == 0)return (v[0] == target);
    bool not_take = isSubsequenceTarget(i-1 , target , v);
    bool take = false;
    if(i < v.size())
        take = isSubsequenceTarget(i-1 , target - v[i] , v);
    return not_take || take;
}

int main()
{
    vector<int> v({1 , 2,  3, 4});
    
    int target = 6 , size = v.size();
    vector<vector<int>> dp(v.size() , vector<int> ( target+1 , 0));
    
    vector<int> prev(target+1 , 0);
    
    prev[0] = 1;
    prev[v[0]] = 1;
    
    for(int i=1;i<size;i++)
    {
        vector<int> cur(target+1 , 0);
        for(int j=1;j<=target;j++)
        {
            bool not_take = prev[j];
            bool take = false;
            if((j - v[i]) >= 0 )
                take = prev[j - v[i]];
            cur[j] = not_take || take;
        }
        prev = cur;
    }
    cout<<prev[target];
    
}