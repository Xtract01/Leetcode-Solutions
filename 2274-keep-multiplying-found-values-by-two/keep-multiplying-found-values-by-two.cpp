class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st;
        int n = nums.size();
        int temp = original;
        for(int i = 0 ; i<n ; i++){
            st.insert(nums[i]);
        }
        while(st.find(temp)!=st.end()) temp *= 2;
        return temp;
    }
};