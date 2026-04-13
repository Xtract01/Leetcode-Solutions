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
    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    ListNode* getKthNode(ListNode* temp , int k){
        k-=1;
        while(temp && k>0){
            k--;
            temp = temp->next;
        }
        return temp; 
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp!=NULL){
            ListNode* KthNode = getKthNode(temp,k);
            if(KthNode==NULL){
                if(prevLast) prevLast->next = temp;
                break;
            }
            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;
            reverseLL(temp);
            if(temp==head){
                head = KthNode;
            }
            else prevLast->next = KthNode;
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};