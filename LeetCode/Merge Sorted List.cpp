#include <bits/stdc++.h>
using namespace std;

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
    void addList(int val , ListNode*&tail)
    {
        ListNode* newNode = new ListNode(val);
        if(tail==NULL)
            tail = newNode;
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }

    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* head=new ListNode(0);
        ListNode* tail = head;
        while(ptr1!=NULL && ptr2!=NULL)
        {
            if(ptr1->val > ptr2->val)
            {
                addList(ptr2->val , tail);
                ptr2 = ptr2->next;
            }
            else
            {
                addList(ptr1->val , tail);
                ptr1 = ptr1->next;
            }
        }
        while(ptr1!=NULL){
        addList( ptr1->val,tail);
        ptr1=ptr1->next;
        }
        while(ptr2!=NULL){
        addList( ptr2->val,tail);
        ptr2=ptr2->next;
        }
            
        return head->next;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,1,2,3};
    cout<<s.subarraysWithKDistinct(v , 2);
}
