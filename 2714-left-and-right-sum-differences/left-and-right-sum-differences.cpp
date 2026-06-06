class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int sum = accumulate(nums.begin(),nums.end(),0);
        int currSum = 0;
        for(int i=0 ; i<n ; i++){
            int leftSum = currSum;
            currSum+=nums[i];
            int rightSum = sum-currSum;
            ans[i] = abs(leftSum-rightSum);
        }
        return ans;
    }
};