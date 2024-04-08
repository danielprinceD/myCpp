#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    long long solver(int* arr , int left , int right , vector<vector<long long>> &dp )
    {
        if(left > right)return 0;
        if(left == right)return dp[left][right] = arr[left];
        if(dp[left][right] != -1)return dp[left][right];
        
        long long L = arr[left] + min(solver(arr , left + 2 , right ,dp ) , solver(arr , left+ 1 , right -1 ,dp));
        long long R = arr[right] + min(solver(arr , left  , right -2 , dp) , solver(arr , left+ 1 , right -1 ,dp));
        
        return dp[left][right] = max(L , R);
    }
    long long maximumAmount(int n, int arr[]){
        vector<vector<long long>> dp (n+1 , vector<long long> (n+1 , -1));
        return solver(arr , 0 , n-1 ,dp);
    }
};



int main()
{
    std::cout<<"Hello World";

    return 0;
}
