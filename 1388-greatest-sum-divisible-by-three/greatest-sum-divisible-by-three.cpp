class Solution {
public:
    int helper(vector<int>& nums ,int n ,int i,int rem , vector<vector<int>> &t){
        if (i >= n) {
            if (rem == 0) return 0;
            return INT_MIN;
        }
        if(t[i][rem]!=-1) return t[i][rem];
        int take = nums[i] + helper(nums,n,i+1,(rem + nums[i]) % 3,t);
        int notTake = helper(nums,n,i+1,rem , t);
        return t[i][rem] = max(take,notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n,vector<int>(3,-1));
        return helper(nums,n,0,0,t);
    }
};