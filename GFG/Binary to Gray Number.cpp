#include <iostream>

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        string bit = "", gray = "";
        for(int i=0;i<=31;i++)
        {
            if(n & (1 << i)) bit = '1'+bit;
            else bit = '0'+bit;
        }
        int minInd = 0;
        for(int i=0;i<=31;i++)
        {
            if(bit[i]=='1')
            {
                minInd = i;
                break;
            }
        }
        bit = bit.substr(minInd , 32-minInd);
        gray+=bit[0];
        int a = bit[0]-'0';
        for(int i=1;i<bit.size();i++)
        {
            int b = bit[i] - '0';
            if(a ^ b)
            {
                gray+='1';
                a = 1;
            }
            else
            {
                gray+='0';
                a = 0;
            }
        }
        
        int ans = 0;
        for(int i=0;i<gray.size();i++)
            ans = ans * 2 + ( gray[i] - '0' );
        
        return ans;
    }
};


int main()
{
    std::cout<<"Hello World";

    return 0;
}
