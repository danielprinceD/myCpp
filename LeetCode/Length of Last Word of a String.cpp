#include <iostream>

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1 , ans = 0;
        while(s[n]==' ')
            n--;
        while(n >= 0 && s[n]!=' ')
        {
            ans++;
            n--;
        }
        return ans;
        
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
