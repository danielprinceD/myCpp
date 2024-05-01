#include <iostream>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = ""; 
        int size = word.size()-1;
        int start = 0;
        for(int i=0;i<=size;i++)
        {
            if(word[i] == ch)
            {
                string temp = word.substr(start , i+1);
                reverse(temp.begin() , temp.end());
                ans+=temp;
                ans+=word.substr(i+1);
                return ans;
            }
        }
        return word;
    }
};

int main()
{
    return 0;
}
