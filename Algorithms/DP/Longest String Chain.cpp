#include <bits/stdc++.h>
using namespace std;


// Longest String Chain


bool possibility(string &a , string &b)
{
    if(a.size() != b.size()+1)return false;
    int first = 0, second = 0;
    while(first < a.size())
    {
        if( second < b.size() && a[first] == b[second])
        {
            first++; second++;
        }else first++;
    }
    if(first == a.size() && second == b.size())return true;
    return false;
}

int longestStrChain(vector<string> &arr){
    int n = arr.size() , maxim  =1;
    auto comp = [](string &a ,string &b){
        return a.size() < b.size();
    };
    sort(arr.begin() , arr.end() , comp);
    vector<int> dp(n , 1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(possibility(arr[i] , arr[j]))
            {
                dp[i] = max(dp[i] , 1 + dp[j]);
                maxim = max(dp[i] , maxim);
            }
        }
    }
    return maxim;
}

int main()
{
    return 0;
}