#include <bits/stdc++.h>
using namespace std;

int ways(int i , int j , string &a , string &b)
{
    if(i < 0) return j+1;
    if(j < 0)return i+1;

    if(a[i] == b[j])
        return ways(i-1 , j-1 , a , b);
    
    return min( 1 + ways(i , j-1 , a ,b) , min ( 1 + ways(i-1 , j, a ,b) , 1 + ways(i-1 , j-1, a ,b) ) );
}

int editDistance(string &str1, string &str2)
{
    int n = str1.length() , m = str2.length();
    vector<int> prev(m+1 , 0) , cur(m+1 , 0);
    for(int i=0;i<=m;i++)
        prev[i] = i;
        
    for(int i=1;i<=n;i++)
    {
        cur[0] = i;
        for(int j=1;j<=m;j++)
            if(str1[i-1] == str2[j-1]) cur[j] = prev[j-1];
            else cur[j] = min( 1 + prev[j-1] ,min( 1 + prev[j] , 1 + cur[j-1] ));
        prev = cur;
    }
    return prev[m];
}

int main()
{
    string str = "wncpoddas" , str2 = "wqegesggfff";
    cout<<editDistance(str , str2);
    return 0;
}