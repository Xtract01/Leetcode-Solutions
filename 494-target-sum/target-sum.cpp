class Solution {
public:
    int f(int ind , int sum , int target , vector<int> &nums ,  unordered_map<string,int> &mp){
        if(ind==nums.size()){
            if(sum==target) return 1;
            return 0;
        }
        string key = to_string(ind) + "_" + to_string(sum);
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        int pos = f(ind+1,sum+nums[ind],target,nums,mp);
        int neg = f(ind+1,sum-nums[ind],target,nums,mp);
        return mp[key] = pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int> mp;
        return f(0,0,target,nums,mp);
    }
};