class Solution {
public:
	bool isPossible(int row , int col ,char ch,  vector<vector<char>> &board)
	{
		for(int i=0;i<=8;i++)
		{
			if(board[row][i] == ch)return false;
			if(board[i][col] == ch)return false;
			if(board[ 3 * (row/3)+(i/3)][3 * (col/3) + (i%3)] == ch)return false;
		}
		return true;
	}
	bool solver( vector<vector<char>> &board)
	{
		for(int row=0;row<=8;row++)
		{
			for(int col=0;col<=8;col++)
			{
				if(board[row][col] == '.')
				{
					for(char ch='1';ch<='9';ch++)
					{
						if(isPossible(row , col , ch , board))
						{
							board[row][col] = ch;
							if(solver(board) == 1)
								return true;
							else board[row][col] = '.';
						}
					}
					return false;
				}
			}
			
		}
		return true;
	}

    void solveSudoku(vector<vector<char>>& board) {
		
		solver(board);
		
		for(auto i : board)
		{
			for(auto j  : i)
				cout<<j<<" ";
			cout<<endl;
		}
    }
};