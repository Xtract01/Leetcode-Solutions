class Solution {
public:
    int M = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int> left_mp;
        unordered_map<int,int> right_mp;
        for(int i=0 ; i<n ; i++){
            right_mp[nums[i]]++;
        }
        for(int &num:nums){
            right_mp[num]--;
            int left = left_mp[num*2];
            int right = right_mp[num*2];
            ans = (ans + (1LL * left * right)) %M;
            left_mp[num]++;
        }
        return ans;
    }
};