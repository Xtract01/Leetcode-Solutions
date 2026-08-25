class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            st.insert(nums[i]);
        }
        int cnt = 1;
        while(true){
            int idx = cnt * k;
            if(!st.count(idx)) return idx;
            cnt++;
        }
        return -1;
    }
};