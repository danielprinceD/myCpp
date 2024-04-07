#include <iostream>

 class Solution{
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{
	    vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
	    
	    for(int i=1;i<=m;i++)
	    {
	        for(int j=i;j<=n;j++)
	        {
	            dp[i][j] = max (dp[i][j-1]  ,  a[j-1] * b[i-1] + dp[i -1 ][j-1] ); 
	        }
	    }
	    return dp[m][n];
 	} 
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
