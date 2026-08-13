class Solution {
public:
    int upperBound(vector<int> &nums, int target){
        int lo = 0 , hi = nums.size() - 1;
        int ans = nums.size();
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]>target){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
    int lowerBound(vector<int> &nums, int target){
        int lo = 0 , hi = nums.size() - 1;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]>=target){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums,target);
        int ub = upperBound(nums,target);
        if (lb == -1 || nums[lb] != target) {
            return {-1, -1};
        }
        return {lb,ub-1};
    }
};