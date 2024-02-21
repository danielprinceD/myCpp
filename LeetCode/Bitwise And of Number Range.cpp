#include <iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt=0;
        while(left != right)
        {
            left >>=1;right>>=1;
            cnt++;
        }
        return left<<cnt;
    }
};
int main()
{
    Solution s;
    cout<<s.rangeBitwiseAnd(1,2147483647);
    return 0;
}
