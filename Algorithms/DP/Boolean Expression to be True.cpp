#include <iostream>
using namespace std;

int mod = 1000000007;

int partition(int i, int j, bool isTrue, string &str, vector<vector<vector<long long>>> &dp) {
    if (i > j) return 0;
    if (i == j) {
        if (isTrue) return (str[i] == 'T') ? 1 : 0;
        else return (str[i] == 'F') ? 1 : 0;
    }
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    long long ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        long long LT = partition(i, ind - 1, true, str, dp) % mod;
        long long LF = partition(i, ind - 1, false, str, dp) % mod;
        long long RT = partition(ind + 1, j, true, str, dp) % mod;
        long long RF = partition(ind + 1, j, false, str, dp) % mod;

        if (str[ind] == '&') {
            if (isTrue) {
                ways = (ways + (LT * RT) % mod) % mod;
            } else {
                ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod;
            }
        } else if (str[ind] == '|') {
            if (isTrue) {
                ways = (ways + (LT * RT) % mod + (LT * RF) % mod + (LF * RT) % mod) % mod;
            } else {
                ways = (ways + (LF * RF) % mod) % mod;
            }
        } else if (str[ind] == '^') {
            if (isTrue) {
                ways = (ways + (LT * RF) % mod + (LF * RT) % mod) % mod;
            } else {
                ways = (ways + (LT * RT) % mod + (LF * RF) % mod) % mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &str) {
    int n = str.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return partition(0, n - 1, true, str, dp);
}


int main()
{
    
    return 0;
}