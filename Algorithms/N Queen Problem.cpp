#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isSafe(int row , int col , vector<string> &board)
    {
        int temp_row = row , temp_col = col;
        while(col >= 0)
        {
            if(board[row][col] == 'Q')return false;
            col--;
        }
        col = temp_col;

        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 'Q')return false;
            col--; row--;
        }

        row = temp_row;
        col = temp_col;

        while(row < board.size() && col >= 0)
        {
            if(board[row][col] == 'Q')return false;
            row++; col--;
        }
        return true;
    }

    void solver(int col , vector<string> &board , vector<vector<string>> &ans)
    {
        if(col == board[0].size())
        {
           ans.push_back(board); return;
        }

        for(int row=0;row<board.size();row++)
        {
            if(isSafe(row , col , board))
            {
                board[row][col] = 'Q';
                solver(col + 1 , board , ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board( n , string (n , '.'));
        solver(0 , board , ans);
        return ans;
    }
};

int main()
{
    int n; cin>>n;
    auto ans = Solution().solveNQueens(n);
    for(auto i : ans)
    {
        for(string j : i)
        {
            for(auto ch : j)
                cout<<ch<<" ";
            cout<<endl;
        }
        cout<<"**********************"<<endl;
    }
}