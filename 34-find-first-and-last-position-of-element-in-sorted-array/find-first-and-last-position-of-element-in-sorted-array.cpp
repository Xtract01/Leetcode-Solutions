class Solution {
public:
    int lowerBound(vector<int> &nums,int target){
        int n = nums.size();
        int lo=0,hi=n-1;
        int ans = n;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>=target){
                ans = mid;
                hi=mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
    int upperBound(vector<int> &nums,int target){
        int n = nums.size();
        int lo=0,hi=n-1;
        int ans = n;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>target){
                ans = mid;
                hi=mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums,target);
        if(lb==nums.size() || nums[lb]!=target) return {-1,-1};
        return {lb,upperBound(nums,target)-1};
    }
};