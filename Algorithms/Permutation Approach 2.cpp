#include <bits/stdc++.h>
using namespace std;

void swap(int i,  int j , string &str)
{
    char ch  = str[i];
    str[i] = str[j];
    str[j] = ch;
}

void permutate(int i , string &str)
{
    if(i == str.size())
    {
        cout<<str<<" ";
        return;
    }
    for(int ind=i;ind<str.size();ind++)
    {
        swap(i , ind , str);
        permutate(i+1 , str);
        swap(i , ind , str);
    }
}

int main()
{
    string str = "dan";
    permutate(0 , str);
    return 0;
}