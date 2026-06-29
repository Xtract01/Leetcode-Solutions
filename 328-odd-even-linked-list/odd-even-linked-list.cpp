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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* a = odd;
        ListNode* b = even;
        ListNode* c = head;
        int cnt = 1;
        while(c!=NULL){
            if(cnt%2==0){
                b->next = c;
                b=b->next;
            }
            else {
                a->next=c;
                a=a->next;
            }
            c=c->next;
            cnt++;
        }
        b->next = NULL;
        a->next = even->next;
        return odd->next;
    }
};