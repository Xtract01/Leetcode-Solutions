class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = INT_MAX;
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= nums[hi]) {
                res = min(res, nums[mid]);
                hi = mid;
            } else {
                res = min(res, nums[lo]);
                lo = mid + 1;
            }
        }
        res = min(res, nums[lo]);
        return res;
    }
};