class Solution {
public:
    bool f(int ind,int target ,vector<int>& nums,vector<vector<int>> &dp){
        if(target==0) return true;
        if(ind == 0 ) return nums[0]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notTake = f(ind-1,target,nums,dp);
        int take = false;
        if(nums[ind]<=target) take=f(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0 ; i<n ; i++){
            sum+= nums[i];
        }
        if(sum % 2 !=0) return false;
        vector<vector<int>> dp(n,vector<int>(sum/2 + 1 , -1));
        return f(n-1,sum/2,nums,dp);
    }
};