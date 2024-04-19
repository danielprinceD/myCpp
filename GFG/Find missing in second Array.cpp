#include <iostream>

class Solution{
	
	
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{
	    vector<int>ans;
	    map<int , int> mp;
	    for(int i=0;i<m;i++)
	       mp[b[i]]++;
	   for(int i=0;i<n; i++)
	    if(mp[a[i]]==0)
	        ans.push_back(a[i]);
	   return ans;
	} 
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
