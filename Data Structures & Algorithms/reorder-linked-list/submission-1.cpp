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
    ListNode* reverseList(ListNode* temp) {
        ListNode* prev = NULL;
        ListNode* curr = temp;
        ListNode* next = NULL;

        while(curr != NULL) {
            // cout<<curr->val<<endl;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;

    }
    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }

        slow->next = reverseList(slow->next);
        // cout<<slow->next->val;
        
        fast = slow->next;
        slow->next = nullptr;
        slow = head;
        

        while(fast != nullptr && slow != nullptr) {
            // cout<<"yes";
            ListNode* one = slow->next;
            ListNode* two = fast->next;
            // cout<<slow->val<<" "<<fast->val<<endl;
            slow->next = fast;
            fast->next = one;

            slow = one;
            fast = two;
        }


    }
};
