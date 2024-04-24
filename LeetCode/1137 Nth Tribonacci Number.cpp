#include <iostream>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int t0 = 0 , t1 = 1 , t2 = 1 , t3=1;
        if(n<=0)return 0; if(n<=t2)return 1;
        for(int i=3;i<=n;i++)
        {
            t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }
        return t3;
    }
};

int main()
{
    return 0;
}
