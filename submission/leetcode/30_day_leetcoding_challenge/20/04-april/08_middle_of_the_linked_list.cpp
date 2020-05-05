/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    	/*
    	// time O(n) | space O(n)
        stack <ListNode *> s;
        for(ListNode* ptr=head;ptr!=NULL;ptr=ptr->next)
        	s.push(ptr);

        //5->2,4->1
        int pop_count=(s.size()-1)/2;
        while(pop_count--) s.pop();
        return s.top();
        */

    	// time O(n) | space O(1)
        //slow->1 unit, fast->2 units
        ListNode* slow=head;
        ListNode* fast=head;

        // s...
        // f
        // .sf.
        // ..s.f

        // s..
        // f
        // .sf

        while(fast!=NULL && fast->next!=NULL)
        {
        	slow=slow->next;
        	fast=fast->next->next;
        }
        return slow;
    }
};