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
    int pairSum(ListNode* head) {
        int n = 1;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        vector<int> vec(n/2,0);
        int cntr = 1;
        temp = head;
        while(temp){
            if(cntr<=n/2) vec[cntr-1]+=temp->val;
            else vec[n-cntr-1] +=temp->val;
            cntr++;
            temp= temp->next;
        }
        return *max_element(vec.begin(),vec.end());
    }
};