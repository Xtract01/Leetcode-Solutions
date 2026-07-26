class Solution {
public:
    int f(vector<int>& nums, int k){
        if(k<0) return 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        int l=0 , r = 0;
        int ans= 0;
        while(r<n){
            mp[nums[r]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0) mp.erase(nums[l]);
                    l++;
                }
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};