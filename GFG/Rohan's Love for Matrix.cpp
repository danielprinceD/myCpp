#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int mod = 1000000007;
    
    int firstElement(int n) {
        int a = 1 , b = 1 , fib = 1;
        for(int i=1;i<n-1;i++)
        {
            fib = (a + b)%mod;
            a = b;
            b = fib;
        }
        return fib;
    }
};


int main()
{
    return 0;
}
