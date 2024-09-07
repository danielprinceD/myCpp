#include <bits/stdc++.h>
using namespace std;

void findBinaryDecimal(int num)
{
    while(num > 0)
    {
        int x = num , place = 1 , decimal = 0;
        while(x > 0)
        {
            if(x % 10)
                decimal += place;
            place *= 10;
            x /= 10;
        }
        cout<<decimal<<" ";
        num -= decimal;
    }
}

int main() {
    int num = 532;
    findBinaryDecimal(num);
    return 0;
}