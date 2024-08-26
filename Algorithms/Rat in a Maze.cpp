#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> ans;
    
    void solver(int i , int j , string dir , vector<vector<int>> &mat , auto vis)
    {
        if(i == mat.size()-1 && j == mat[0].size()-1 && mat[i][j] != 0)
        {
            ans.push_back(dir);
            return;
        }
        if(i < 0 || j < 0 || j >= mat[0].size() || i >= mat.size() || mat[i][j] == 0 || vis[i][j] == 1)
            return;
        vis[i][j] = 1;
        
		solver(i-1 , j  , dir + 'U' , mat , vis);
        solver(i+1 , j  , dir + 'D' , mat , vis);
        solver(i , j+1  , dir + 'R' , mat , vis);
        solver(i , j-1  , dir + 'L' , mat , vis);

        vis[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        string dir = "";
		int n = mat.size();
		vector<vector<bool>> vis(n , vector<bool> (n , 0));
        solver(0 , 0 , dir , mat , vis);
		if(ans.size() != 0)return ans;
		ans.push_back("-1");
        return ans;
    }
};

int main()
{
	int n; cin>>n;
	vector<vector<int>> board(n , vector<int> (n , 0));

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>board[i][j];
	auto ans = Solution().findPath(board);
	for(auto it : ans)
		cout<<it<<endl;
}