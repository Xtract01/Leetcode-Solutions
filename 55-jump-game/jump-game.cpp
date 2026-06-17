class Solution {
public:
    bool solve(int ind , vector<int> &nums ,int n, vector<int> &dp){
        if(ind>=n) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=1 ; i<=nums[ind] ; i++){
            if(solve(ind+i,nums,n,dp)) return dp[ind]=true;
        }
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,n-1,dp);
    }
};