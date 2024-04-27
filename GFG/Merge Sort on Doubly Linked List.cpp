#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    struct Node* getMid(Node* head)
    {
        struct Node* fast = head , *slow = head;
        while(!fast->next && !fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *temp = slow->next;
        slow->next = NULL;
        return temp;
    }
    
    struct Node* merge(Node* first , Node* second)
    {
        if(!first )return second;
        if(!second)return first;
        
        if(first->data < second->data)
        {
            first->next = merge(first->next , second);
            first->next->prev = first;
            first->prev = NULL;
            return first;
        }else 
        {
            second->next = merge(first , second->next);
            second->next->prev = second;
            second->prev = NULL;
            return second;
        }
    }
    
    struct Node *sortDoubly(struct Node *head) {
        if(!head || !head->next)return head;
        
        Node* mid = getMid(head);
        head = sortDoubly(head);
        mid = sortDoubly(mid);
        
        return merge(head , mid);
    }
};


int main()
{
    
}
