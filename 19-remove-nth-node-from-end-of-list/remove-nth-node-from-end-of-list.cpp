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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp1 = dummy ; ListNode* temp2 = dummy;
        for(int i=0 ; i<=n ; i++) temp1=temp1->next;
        while(temp1!=NULL){
            temp1=temp1->next;
            temp2 = temp2->next;

        }
        temp2->next = temp2->next->next;
        return dummy->next;
    }
};