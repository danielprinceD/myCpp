#include <iostream>

int longestSubarrayWithSumK(vector<int> a, long long k) {
    unordered_map<long long , int> ds;
    long long sum = 0; int maxLength = 0;
    for(int i=0;i<a.size();i++)
    {
         sum += a[i];
         if(sum == k)
            maxLength = max(maxLength , i+1);
        
         if(ds.find(sum - k) != ds.end())
            maxLength = max(maxLength , i - ds[sum-k]);
        if(ds.find(sum) == ds.end())
            ds[sum] = i;
    }

    return maxLength;
}

int main()
{
}