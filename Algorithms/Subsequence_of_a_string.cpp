#include<bits/stdc++.h>
using namespace std;

void powerSet(string &s )
{
    int n = s.length() , end = (1<<n)-1;
    for(int num=0;num<=end;num++)
    {
        string temp = "";
        for(int i=0;i<n;i++)
            if(num & (1 << i))
                temp+= s[i];
        cout<<temp<<" ";
    }
}

void recursiveMethod( int ind , string &newStr, string &str){
    if(ind >= str.size())
    {
        cout<<newStr<<" ";
        return;
    }
    newStr += str[ind];
    recursiveMethod(ind+1 , newStr , str);
    newStr.pop_back();
    recursiveMethod(ind+1 , newStr , str);
}

int main(){
    string s = "";
    string em = "";
    recursiveMethod(0 ,em ,  s);
    
}