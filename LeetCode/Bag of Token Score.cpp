#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i = 0 , score = 0 , maxScore = 0;
        int j = tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        while(i <= j)
        {
            if(tokens[i] <= power)
            {
                power -=tokens[i];
                score++;
                i++;
            }
            else if(tokens[i] > power && score > 0)
            {
                power+=tokens[j];
                score--;
                j--;
            }
            else
            {
                i++;
            }
            maxScore = max(maxScore , score);
        }
        return maxScore;
    }
};

int main()
{
    vector<int> v = {200 , 100};
    Solution s;
    cout<<s.bagOfTokensScore(v , 150);
}
