class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &str)
    {
        int i = 0 , j = str.size()-1;
        while(i < j)
        {
            if(str[i] != str[j])
                return false;
            i++; j--;
        }
        return true;
    }
    void solver(int ind, string &str , vector<string> &ds){
        if(ind == str.size())
        {
            ans.push_back(ds);
            return;
        }
        string temp = "";
        for(int i=ind;i<str.size();i++)
        {
            temp += str[i];
            if(isPalindrome(temp))
            {
                ds.push_back(temp);
                solver(i+1 , str , ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        solver(0 , s ,ds);
        return ans;
    }
};