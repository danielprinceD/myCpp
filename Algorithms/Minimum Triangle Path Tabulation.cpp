#include <bits/stdc++.h>
using namespace std;

int triangleMinimum(int r , int c , vector<vector<int>> &v)
{
    if(r > v.size() || c > v[0].size())return 0;
    if(r == v.size()-1 )return v[r][c];
    return min(v[r][c] + triangleMinimum(r+1 , c , v) , v[r][c] + triangleMinimum(r+1 , c+1, v)); 
}

int main()
{   
    vector<vector<int>> v({
        {2 , 0 , 0 , 0},
        {2 , 3 , 0 , 0},
        {4 , 2 , 2 , 0},
        {1 , 4 , 12 , 10},
    });
    int r = v.size(); 
    int c = v[0].size();
    
    vector<vector<int>> dp(v.size() , vector<int> ( v[0].size(), 0));
    
    vector<int> prev(c , 0);
    
    for(int i=0;i<c;i++)
        prev[i] = v[r-1][i];
    
    for(int i=r-2;i>=0;i--)
    {
        vector<int> cur(c , 0);
        for(int j=c-1;j>=0;j--)
        {
            int left = v[i][j] + prev[j] , right = (j < c) ? v[i][j] +  prev[j+1] : 1e9;
            cur[j] = min(left ,right );
        }
        prev = cur;
    }
    cout<<prev[0];
    
    return 0;
}