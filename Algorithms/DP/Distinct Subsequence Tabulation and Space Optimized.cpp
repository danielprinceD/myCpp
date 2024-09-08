#include <bits/stdc++.h>
using namespace std;

int countWays(int i , int j , string &a , string &b){
    
    if(j <= 0)return 1;
    if(i <= 0)return 0;
    
    if(a[i-1] == b[j-1])
        return countWays(i-1, j-1, a, b) + countWays(i-1 , j , a , b);
    return countWays(i-1 , j , a , b);
}


int distinctSubsequences(string &a, string &b)
{
	int n = a.length() , m = b.length();
	int mod = 1e9+7;
	vector<int> prev(m+1 , 0);
	vector<int> cur(m+1 , 0);

	prev[0] =cur[0] = 1;

	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=m;j++)
		{
    		if(a[i-1] == b[j-1])
				cur[j] = ( prev[j-1] + prev[j] ) % mod;
			else 
				cur[j] = prev[j] % mod;
		}
		prev = cur;
	}
	return prev[m];
}

// Space Optimized Code for https://www.naukri.com/code360/problems/subsequence-counting_3755256?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION


int main()
{
    string s1 = "brootgroot" , s2 = "brt";
    cout<<distinctSubsequences(s1 , s2);
    return 0;
}