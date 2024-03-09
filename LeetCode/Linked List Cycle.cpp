#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*ptr = head;
       map<ListNode* , int> mp;
       while(ptr!=NULL)
       {
           if(mp[ptr]<1)
            mp[ptr]++;
            else
            return 1;
        ptr = ptr->next;
       }
       return 0;
    }
};

int main()
{
    ListNode *one = new ListNode(10);
    ListNode *two = new ListNode(20);
    ListNode *three = new ListNode(30);
    ListNode *four = new ListNode(40);
    one->next = two;
    two->next = three;
    three->next = four;
    Solution s;
    cout<<s.hasCycle(three);

    
}