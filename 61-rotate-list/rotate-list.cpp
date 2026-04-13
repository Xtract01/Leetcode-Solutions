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
    ListNode* findNthNode(ListNode* head, int n){
        int cnt = 1;
        ListNode *temp = head;
        while(cnt!=n){
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 1;
        ListNode* tail = head;
        if(!head || !head->next) return head;
        while(tail->next){
            len++;
            tail = tail->next;
        }
        if(k%len==0) return head;
        k = k%len;
        tail->next = head;
        ListNode* newLastNode = findNthNode(head,len-k);
        head = newLastNode->next;
        newLastNode->next = NULL;
        return head;
    }
};