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
    ListNode* merge2(ListNode* h1 , ListNode* h2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* temp1 = h1;
        ListNode* temp2 = h2;
        while(temp1 && temp2){
            if(temp1->val<temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else {
                temp->next = temp2;
                temp2=temp2->next;
            }
            temp = temp->next;
        }
        if(temp1){
            temp->next = temp1;
        }
        if(temp2) temp->next = temp2;
        return dummy->next;
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode * fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* middle = findMiddle(head); 
        ListNode * leftHead = head ;
        ListNode* rightHead = middle->next;
        middle->next = NULL;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return merge2(leftHead,rightHead);
    }
};