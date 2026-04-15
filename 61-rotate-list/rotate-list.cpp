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
    ListNode* getNthNode(ListNode* head,int n){
        ListNode* temp = head;
        int cnt = 1;
        while(cnt!=n){
            temp=temp->next;
            cnt++;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int len = 1;
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
            len++;
        }
        k = k%len;
        if(k==0)  return head;
        temp->next = head;
        ListNode* newEndNode = getNthNode(head,len-k);
        ListNode* newStart = newEndNode->next;
        newEndNode->next = NULL;
        return newStart;
    }
};