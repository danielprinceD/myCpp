#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int  , ListNode* > mp;
        
        ListNode* ptr = new ListNode(0);
        ptr->next = head;
        int sum =0;
        mp[0] = ptr;
        while(head!=NULL)
        {
            sum +=head->val;
            if(mp.find(sum) != mp.end())
            {
                ListNode* start = mp[sum];
                int pf = sum;
                ListNode*temp = start;
                while(temp->next != head)
                {
                    temp = temp->next;
                    pf += temp->val;
                    mp.erase(pf);
                }
                start->next = head->next;
                
            }
            else{
                mp[sum] = head;
            }
            head = head->next;
        }
        head = ptr->next;
        delete ptr;
        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* head1 = new ListNode(2);
    ListNode* head2 = new ListNode(-3);
    ListNode* head3 = new ListNode(3);
    ListNode* head4 = new ListNode(1);
    head->next = head1;
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    Solution s;
    ListNode *n= s.removeZeroSumSublists(head);
    while(n!=nullptr)
    {
        cout<<n->val<<" ";
        n=n->next;
    }
}
