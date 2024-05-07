#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        string str = "" , prev = "";
        for(ListNode* ptr = head; ptr ; ptr = ptr->next)
            str+=(char)(ptr->val + '0');
        int bal = 0;
        ListNode *ans = NULL;
        for(int i=str.size()-1; i>=0 ; i--)
        {
            int cur = ((str[i] - '0') * 2 ) + bal;
            bal = (cur > 9) ? 1 : 0;
            cur %= 10;
            ListNode* temp = new ListNode(cur);
            if(!ans)
            {
                ans = temp;
            }
            else 
            {
                temp->next = ans;
                ans = temp;
            }
        }
        if(bal){
            ListNode* temp = new ListNode(bal);
            temp->next = ans;
            ans = temp;
        }
        return ans;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
