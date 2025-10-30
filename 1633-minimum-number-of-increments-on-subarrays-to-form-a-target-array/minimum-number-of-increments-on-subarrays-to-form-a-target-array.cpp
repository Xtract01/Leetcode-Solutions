class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int prev = 0;
        int curr = 0;
        int res = 0;
        for(int i=0; i<n;i++){
            curr=target[i];
            if(abs(curr)>abs(prev)) res+=abs(curr-prev);
            prev=curr;
        }
        return res;
    }
};