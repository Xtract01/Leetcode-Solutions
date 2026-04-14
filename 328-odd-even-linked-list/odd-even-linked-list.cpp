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
        ListNode* odd = new ListNode(100);
        ListNode* even = new ListNode(101);
        ListNode* temp = head;
        ListNode* tempo = odd;
        ListNode* tempe = even;
        int cnt = 0;
        while(temp){
            if(cnt%2==0){
                tempe->next = temp;
                tempe=tempe->next;
            }
            else{
                tempo->next = temp;
                tempo = tempo->next;
            }
            temp = temp->next;
            cnt++;
        }
        tempo->next = NULL;
        tempe->next = odd->next;
        return even->next;
    }
};