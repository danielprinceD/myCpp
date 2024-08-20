#include <bits/stdc++.h>
using namespace std;

int partition(int i , int j , vector<int> &arr)
{
    if(i == j )return 0;
    int mini = 1e9;
    for(int k=i;k<j;k++)
        mini = min(mini , arr[i-1] * arr[k] * arr[j] + partition( i , k , arr ) + partition(k+1 , j , arr));
    
    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    return partition(1 , N-1 , arr);
}

int main()
{
    vector<int> arr({10 , 20 , 30 });
    int n = arr.size();
    vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0));
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            int mini = 1e9;
            for(int k=i;k<j;k++)
                mini = min(mini , arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j] );
            dp[i][j] = mini;
        }
    }
    cout<<dp[1][n-1];
    return 0;
}