class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        int s = sum/2;
        vector<vector<bool>> dp(n,vector<bool>(s+1,false));
        for(int i=0 ; i<n ; i++){
            dp[i][0] = true;
        }
        if(nums[0]<=s) dp[0][nums[0]] = true;

        for(int ind = 1; ind<n ; ind++){
            for(int target = 1 ; target<=s ; target++){
                bool take = false;
                if(target>=nums[ind]) take  = dp[ind-1][target-nums[ind]];;
                bool notTake = dp[ind-1][target];
                dp[ind][target] = take || notTake;
            }
        }
        return dp[n-1][s];
    }
};