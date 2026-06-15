class Solution {
public:
    bool solve(int ind ,vector<int>& nums , vector<int> &dp){
        if(ind>=nums.size()-1) return true;
        if(dp[ind]!=-1) return dp[ind];
        int k = nums[ind];
        for(int j=1 ; j<=k ; j++){
            if(solve(ind+j,nums,dp)) return dp[ind]=true;
        }
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
    }
};