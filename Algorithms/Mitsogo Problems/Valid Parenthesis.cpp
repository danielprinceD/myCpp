#include <bits/stdc++.h>
using namespace std;

bool isValid(string &str)
{
    int stack = 0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == ')')
        {
            if(stack <= 0)
                return 0;
            stack--;
        }
        if(str[i] == '(')
            stack++;
    }
    if(stack == 0)
        return 1;
    return 0;
}

int main()
{
    string str = "(()))";
    cout<<isValid(str);
}