bool isPalindrome(string &str)
{
    string temp = str;
    reverse(temp.begin() , temp.end());
    return temp==str;
}
int partition(int i, string &str)
{
    if(i == str.length())
        return 0;
    string temp = "";
    int mini = 1e9;
    for(int j=i;j<str.length();j++)
    {
        temp += str[j];
        int cost = 1e9;
        if(isPalindrome(temp))
            cost = 1 + partition(j+1, str);
        mini = min(mini , cost);
    }
    return mini;
}
int palindromePartitioning(string str)
{
    int n = str.length();
    vector<int> dp(n+1 , 0);

    for(int i=n-1;i>=0;i--)
    {
        string temp = "";
        int mini = 1e9;
        for(int j=i;j<n;j++)
        {
            temp += str[j];
            int cost = 1e9;
            if(isPalindrome(temp))
                cost = 1 + dp[j+1];
            mini = min(mini , cost);
        }
        dp[i] = mini;
    }

    return dp[0]-1;
}
