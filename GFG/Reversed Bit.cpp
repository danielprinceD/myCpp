#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long reversedBits(long long x) {
        long long num;
        for(int i=0;i<32;i++)
            if(x & (1 << i))
                num += (long long)pow(2 , 31-i);
        return num;
    }
};


int main()
{
}
