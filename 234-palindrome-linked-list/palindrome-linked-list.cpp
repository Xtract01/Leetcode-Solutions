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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* last = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head ; ListNode* slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head1 = reverse(slow->next);
        slow->next = NULL;
        while(head1){
            if(head->val!=head1->val) return false;
            head  = head->next;
            head1=head1->next;
        }
        return true;

    }
};