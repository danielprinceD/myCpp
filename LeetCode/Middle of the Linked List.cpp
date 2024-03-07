#include <iostream>
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
    ListNode* middleNode(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        while(first->next!=NULL)
        {
            if(first->next->next!=NULL)
                second = second->next;
            else if(first->next !=NULL)
                return second->next;
            first = first->next->next;
        }
        return second;
    }
};

void print(ListNode* root)
{
    if(root==NULL)return;
    cout<<root->val<<" ";
    print(root->next);
}

int main()
{
    Solution s;
    ListNode* first = new ListNode(10);
    ListNode* second = new ListNode(20);
    ListNode* third = new ListNode(30);
    ListNode* four = new ListNode(40);
    ListNode* five = new ListNode(50);
    
    first->next = second;
    second->next = third;
    third->next = four;
    four->next = five;
    print(first);
    ListNode* root = s.middleNode(first);
    cout<<endl<<"The Middle Element is "<<root->val;
    
    return 0;
}