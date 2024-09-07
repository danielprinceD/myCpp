#include <bits/stdc++.h>
using namespace std;
int k = 0;
void zig_zag(string &str , int n)
{
    int k = 0; int size = str.size();
    while(k < n)
    {
        int i = k;
        if(k == 0 || k == n-1)
        {
            while(i < size)
            {
                cout<<str[i];
                i+=2*(n-1);
            }
        }
        else{
            int is_rev = true;
            
            while(i < size)
            {
                if(is_rev)
                {
                    cout<<str[i];
                    i+=2 * (n-k-1);
                }
                else 
                {
                    cout<<str[i];
                    i+=2 * (k);
                }
                is_rev = !is_rev;
            }
            
        }
        k++;
    }
}

int main()
{
    int k = 0;
    string str = "abcdefghijklmnopqrstuvwxyz";
    zig_zag(str , 3);
}