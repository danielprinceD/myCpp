#include <bits/stdc++.h>
using namespace std;

void zigzag_string(string &str)
{
    int i = 0 , n = str.size();
    while(i < n)
    {
        cout<<str[i];
        i+=4;
    }
    i = 1;
    while(i < n)
    {
        cout<<str[i];
        i+=2;
    }
    i = 2;
    while(i < n)
    {
        cout<<str[i];
        i+=4;
    }
}

int main()
{
    string str = "abcdefghijklmnop";
    zigzag_string(str);
    return 0;
}