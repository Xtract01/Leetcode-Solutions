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
    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwo(ListNode* lst1 , ListNode* lst2){
        ListNode *temp1 = lst1;
        ListNode* temp2 = lst2;
        ListNode* dummy = new ListNode(0);
        ListNode* tempD = dummy;
        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                tempD ->next = temp1;
                temp1 = temp1->next;
            }
            else {
                tempD->next = temp2;
                temp2 = temp2->next;
            }
            tempD = tempD->next;
        }
        if(temp1) tempD->next = temp1;
        if(temp2) tempD->next = temp2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        ListNode* left = head;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);
        return mergeTwo(right,left);
    }
};