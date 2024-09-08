#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

int partition(int i , int j , vector<int> &a)
{
	if(i > j) return 0;
	int maxi = -1e9;
	for(int ind=i;ind<=j;ind++)
	{
		int cost = a[i-1] * a[j+1] * a[ind] + partition(i, ind-1 , a)+ partition(ind+1, j , a);
		maxi = max(maxi , cost);
	}
	return maxi;
}

int maxCoins(vector<int>& a)
{
	a.push_back(1);
	a.insert(a.begin() , 1);
	int n = a.size();
	vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0));
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(i > j)continue;
			int maxi = -1e9;
			for(int ind=i;ind<=j;ind++)
			{
				int cost = a[i-1] * a[j+1] * a[ind] + dp[i][ind-1]+ dp[ind+1][j];
				maxi = max(maxi , cost);
			}
			dp[i][j] = maxi;
		}
	}
	return dp[1][n-2];
}

int main()
{
    int n; cin>>n;
    vector<int> v(n , 0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int pos , ele; cin>>pos>>ele;
    v.insert(v.begin()+pos-1 , ele);
    for(int i=0;i<v.size();i++)
        cout<<v[i];
    return 0;
}