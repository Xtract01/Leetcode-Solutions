class Solution {
public:
    bool solve(int i, int sum , vector<int> &nums,vector<vector<int>> &dp){
        if(sum==0) return true;
        if(i==0) return nums[0] == sum;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool take = false;
        if(sum>=nums[i]) take = solve(i-1,sum-nums[i],nums,dp);
        bool notTake = solve(i-1,sum,nums,dp);
        return dp[i][sum]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        return solve(n-1,sum/2,nums,dp);
    }
};