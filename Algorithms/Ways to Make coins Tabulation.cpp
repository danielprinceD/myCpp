#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value+1 , 0);

    for(int target=0;target<=value;target++)
        if(target % denominations[0] == 0)
            prev[target] = 1;

    for(int i=1;i<n;i++)
    {
        vector<long> cur(value+1 , 0);
        for(int target=0;target<=value;target++)
        {
            long take = 0 , notTake = 0;
            notTake = prev[target];
            if(denominations[i] <= target)
                take = cur[target - denominations[i]];
            cur[target] = take + notTake;
        }
        prev = cur;
    }


    return prev[value];
}


// https://www.naukri.com/code360/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos