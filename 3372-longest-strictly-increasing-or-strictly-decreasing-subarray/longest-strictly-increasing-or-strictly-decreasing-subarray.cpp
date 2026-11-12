
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int increase = 1;
        int decrease = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                increase++;
                decrease = 1;
            }
            else if(nums[i] < nums[i-1]) {
                decrease++;
                increase = 1;
            }
            else {
                increase = 1;
                decrease = 1;
            }

            ans = max(ans, max(increase, decrease));
        }

        return ans;
    }
};
