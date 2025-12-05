class Solution {
public:
    int f(int ind , int sum , int target , vector<int> &nums){
        if(ind==nums.size()){
            if(sum==target) return 1;
            return 0;
        }
        int pos = f(ind+1,sum+nums[ind],target,nums);
        int neg = f(ind+1,sum-nums[ind],target,nums);
        return pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(0,0,target,nums);
    }
};