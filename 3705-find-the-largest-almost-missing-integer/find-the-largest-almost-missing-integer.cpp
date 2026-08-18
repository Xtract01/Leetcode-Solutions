class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num : nums) {
            mp[num]++;
        }
        int n = nums.size();
        if(k == 1) {
            int maxi = INT_MIN;

            for(auto it : mp) {
                if(it.second == 1)
                    maxi = max(maxi, it.first);
            }
            return maxi == INT_MIN ? -1 : maxi;
        }
        else if (k == n) {
            int maxi = INT_MIN;

            for (auto it : mp) {
                maxi = max(maxi, it.first);
            }

            return maxi;
        }
        else {
            if(mp[nums[0]] == 1 && mp[nums[n-1]] == 1)
                return max(nums[0], nums[n-1]);
            else if(mp[nums[0]] == 1)
                return nums[0];
            else if(mp[nums[n-1]] == 1)
                return nums[n-1];
        }

        return -1;
    }
};