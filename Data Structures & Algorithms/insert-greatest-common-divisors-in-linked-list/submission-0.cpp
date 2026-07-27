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
private: 
    int gcd(int a, int b) {
        if(a > b) return gcd(b,a);

        if(a == 0) return b;

        return gcd(b%a, a);
    }

    void insertBet(ListNode* one, ListNode* two, int val) {
        ListNode* mid = new ListNode(val);

        one -> next = mid;
        mid -> next = two;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next)
            return head;

        ListNode* prev = head;
        ListNode* nex = head->next;

        while(prev != NULL && nex != NULL) {
            int g = gcd(prev->val, nex->val);
            // cout<<g<<endl;
            insertBet(prev, nex, g);

            prev = nex;
            nex = nex->next;
        }

        return head;
    }
};