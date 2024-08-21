#include <bits/stdc++.h> 
using namespace std;

int finder(int i , int j , vector<int>&cuts)
{
    if(i > j)return 0;

    int mini = 1e9;
    for(int ind=i;ind<=j;ind++)
    {
        int cost = cuts[j+1] - cuts[i-1] + finder(i , ind-1 , cuts) + finder(ind+1 , j ,cuts);
        mini = min(mini , cost);
    }

    return mini;
}

int cost(int n, int c, vector<int> &cuts){
    cuts.insert(cuts.begin() , 0);
    cuts.push_back(n);
    sort(cuts.begin() , cuts.end());
    vector<vector<int>> dp(c+2 , vector<int>(c+2 , 0));

    for(int i=c;i>=1;i--)
        for(int j=1;j<=c;j++)
        {
            if(i > j)continue;
            int mini = 1e9;
            for(int ind=i;ind<=j;ind++)
                mini = min(mini , cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j]);
            dp[i][j] = mini;
        }

    return dp[1][c];   
}
int main()
{
    std::cout<<"Hello World";

    return 0;
}