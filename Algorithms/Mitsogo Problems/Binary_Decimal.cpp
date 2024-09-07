#include <bits/stdc++.h>
using namespace std;

void get_binary(int n , vector<int> &bin)
{
    int digits = log10(n) + 1;
    for(int i=0;i<(1<<digits);i++)
    {
        int val = 0;
        for(int j=0;j<digits;j++)
        {
            if(i & (1<<j))
                val = val * 10 + 1;
            else val = val * 10;
        }
        bin.push_back(val);
    }
}

void allPossible(int n , vector<int> &bin , vector<int> &ds , vector<int> &ans)
{
    if(n < 0 || ds.size() > ans.size())return;
    if(n == 0)
    {
        ans = ds;
        return;
    }
    for(int i : bin)
    {
        ds.push_back(i);
        allPossible(n - i , bin , ds , ans);
        ds.pop_back();
    }
}

void binary_decimal(int n)
{
    vector<int> binaries;
    vector<int> ds , ans(n , 1);
    get_binary(n , binaries);
    allPossible(n , binaries , ds , ans);
    for(int i : ans)
        cout<<i<<" ";
}

int main()
{
    int n = 400;
    binary_decimal(n);
}