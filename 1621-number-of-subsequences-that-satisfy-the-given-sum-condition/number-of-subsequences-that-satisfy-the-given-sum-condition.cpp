class Solution {
public:
    int MOD = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        vector<long long> power(n);
        power[0] = 1;

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }
        int i =0 ,j = n-1;
        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                ans = (ans + power[j - i]) % MOD;
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};