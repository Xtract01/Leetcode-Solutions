class Solution {
public:
    int solve(vector<int>& temp) {
        int n = temp.size();
        if(n==0) return 0;
        if(n==1) return temp[0];
        vector<int> dp(n,0);
        dp[0] = temp[0];
        dp[1] = max(temp[1],dp[0]);
        for(int i = 2 ; i<n ; i++){
            int take = temp[i] + dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take,notTake);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> temp1 , temp2;
        for(int i = 0 ; i< n ; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        int ans1 = solve(temp1);
        int ans2 = solve(temp2);
        return max(ans1,ans2);
    }
};