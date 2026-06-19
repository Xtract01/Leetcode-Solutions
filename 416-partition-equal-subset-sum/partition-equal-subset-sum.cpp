class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        int s = sum/2;
        vector<bool> prev(s+1,false) , curr(s+1,false);
        prev[0] = curr[0] = true;
        if(nums[0] <= s) prev[nums[0]] = true;
        for(int ind = 1; ind<n ; ind++){
            for(int target = 1 ; target<=s ; target++){
                bool take = false;
                if(target>=nums[ind]) take  = prev[target-nums[ind]];
                bool notTake = prev[target];
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[s];
    }
};