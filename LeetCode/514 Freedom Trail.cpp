#include <iostream>
using namespace std;

class Solution {
public:
    int dis(int cur , int next , int size){
        int between = abs(cur - next );
        int around = size - between;
        return min(around , between);
    }
    int solver(int ringi , int keyi , string &ring , string &key ,vector<vector<int>> &dp){
        if(keyi == key.size())return 0;
        if(dp[ringi][keyi] != -1 )return dp[ringi][keyi];

        int mini = INT_MAX;
        for(int i=0;i<ring.size();i++)
        {
            if(key[keyi] == ring[i])
            {
                int steps = dis(ringi , i , ring.size()) + 1 + solver(i , keyi + 1 , ring , key , dp);
                mini = min(mini , steps);
            }
        }
        return dp[ringi][keyi] = mini;
    }   
    int findRotateSteps(string ring, string key) {
         int n = ring.size() , m = key.size();
         vector<vector<int>> dp(n , vector<int> (m , -1));
         return solver(0 , 0 , ring , key ,dp ); 
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
