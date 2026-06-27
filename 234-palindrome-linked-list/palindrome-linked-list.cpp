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
    ListNode* reverseLL (ListNode* head){
        if(!head || !head->next) return head;
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head ; ListNode *fast=head;
        while( fast->next != NULL && fast->next->next != NULL ){
            slow = slow->next;
            fast=fast->next->next;
        }
        slow->next = reverseLL(slow->next);
        slow = slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val) return false;
            slow = slow->next;
            head  =head->next;
        }
        return true;

    }
};