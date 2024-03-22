#include <stdio.h>
using namespace std;


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head = head->next;
        }
        int i=0 , j = v.size()-1;
        while(i < j)
        {
            if(v[i] != v[j])return 0;
            i++;j--;
        }
        return 1;
    }
};

int main()
{
    
}
