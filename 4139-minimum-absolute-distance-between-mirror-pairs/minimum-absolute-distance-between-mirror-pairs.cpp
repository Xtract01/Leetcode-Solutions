class Solution {
public:
    int reverse(int x){
        int res = 0;
        while(x>0){
             res = res * 10 + (x % 10);
            x/=10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int ans = INT_MAX;
        for(int j = 0; j < nums.size(); j++){
            if(mp.find(nums[j]) != mp.end()){
                ans = min(ans, j - mp[nums[j]]);
            }
            mp[reverse(nums[j])] = j;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};