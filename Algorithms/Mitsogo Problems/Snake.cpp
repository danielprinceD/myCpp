#include <bits/stdc++.h>
using namespace std;

void snake(int n)
{
    int k = 0;
    for(int i=1;i<=n;i++)
    {
        int times = n;
        int start = k + 1;
        int end = n * i;
        while(times > 0)
        {
            if(i & 1)
                cout<<start++;
            else
                cout<<end--;
            times--;
        }
        k += n;
        cout<<endl;
    }
}

int main()
{
    snake(3);
}