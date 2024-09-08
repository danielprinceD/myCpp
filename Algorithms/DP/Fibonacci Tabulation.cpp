#include <bits/stdc++.h>
using namespace std;

int fiboDP(int num , vector<int>&fibo)
{
    if(fibo[num] != -1)return fibo[num];
    return fibo[num] = fiboDP(num -1 , fibo) + fiboDP(num - 2 , fibo);   
}

int main()
{
    vector<int> fibo(11 , -1);
    int prev0 = 0;
    int prev1 = 1;
    int cur;
    for(int i=2;i<=10;i++)
    {
        cur = prev0 + prev1;
        prev0 = prev1;
        prev1 = cur;
    }
    cout<<cur;
    return 0;
}