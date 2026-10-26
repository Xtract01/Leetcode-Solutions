class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nums1(nums.begin(),nums.end());
        nums1.insert(nums1.end(), nums.begin(), nums.end());
        int n = nums.size();
        stack<int> st;
        vector<int> res(n,-1);
        for(int i=2*n-1 ; i>=0 ;i--){
            int idx = i%n;
            while(!st.empty() && nums[idx]>=st.top()){
                st.pop();
            }
            if(i < n && !st.empty()) {
                res[idx] = st.top();
            }
            st.push(nums[idx]);
        }
        return res;
    }
};