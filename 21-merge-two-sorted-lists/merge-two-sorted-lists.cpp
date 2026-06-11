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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* head1 = head;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                head->next = temp1;
                temp1 = temp1->next;
                head = head->next;
            }
            else if(temp1->val>temp2->val){
                head->next = temp2;
                temp2 = temp2->next;
                head = head->next;
            }
        }
        if(temp1){
            head->next = temp1;
        }
        if(temp2){
            head->next = temp2;
        }
        return head1->next;
    }
};