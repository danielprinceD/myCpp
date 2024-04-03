#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solver(vector<vector<char>>& board, string word , int pos , int i , int j , int row , int col , vector<vector<int>> &vis)
    {
        if(pos == word.size()-1){return true;}
        
            
        vis[i][j] = 1;
        
        if(i+1 < row && !vis[i+1][j] && board[i+1][j] == word[pos+1] && solver(board , word , pos + 1 , i+1 , j , row , col  , vis))
            return true;
        
        if(i-1 >= 0 && !vis[i-1][j] && board[i-1][j] == word[pos+1] && solver(board , word , pos + 1 , i-1 , j , row , col  , vis))
            return true;
        
        if(j+1 < col && !vis[i][j+1] && board[i][j+1] == word[pos+1] && solver(board , word , pos + 1 , i , j+1 , row , col  , vis))
            return true;
        
        if(j-1 >= 0 && !vis[i][j-1] && board[i][j-1] == word[pos+1] && solver(board , word , pos + 1 , i , j-1 , row , col  , vis))
            return true;
        
        return vis[i][j] = 0;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>vis(board.size() , vector<int> (board[0].size() , 0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(word[0] == board[i][j] && 
                solver(board , word  , 0 , i , j , board.size() , board[0].size() , vis )  )return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = {
        {'S' , 'E' , 'E' , 'A'},
        {'E' , 'A' , 'M' , 'S'},
        {'S' , 'S' , 'Z' , 'E'}
    };
    cout<<s.exist(board , "SEZ");
}
