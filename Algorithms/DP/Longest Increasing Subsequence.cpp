#include <bits/stdc++.h>
using namespace std;

// Longest Increasing Subsequence - https://leetcode.com/problems/longest-increasing-subsequence/


int longestsize(int i , int last , int n  ,int *arr)
{
    if(i == n)return 0;
    int pick = -1e9 , notPick = -1e9;
    if(last < arr[i])
        pick = 1 + longestsize(i+1, arr[i] ,n , arr);
    notPick = longestsize(i+1, last,n ,  arr);
    return max(notPick , pick);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    return longestsize( 0 , -1e9 ,n, arr);
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n+1 , 0) , cur(n+1 , 0);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int last=i-1;last>=-1;last--)
            {
                int pick = -1e9 , notPick = -1e9;
                if(last == -1 || nums[last] < nums[i])
                    pick = 1 + prev[i+1];
                cur[last+1] = max(prev[last+1] , pick);
            }
            prev = cur;
        }
        return prev[0];
    }
};


int main()
{
    int arr[] = {5, 4 ,11, 1 ,16, 8};
    cout<<longestIncreasingSubsequence(arr , 6);
	return 0;
}