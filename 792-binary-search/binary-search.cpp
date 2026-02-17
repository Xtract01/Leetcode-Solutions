class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int l = nums.size()-1;
        int mid = s+(l-s)/2;
        while(s<=l){
            if(nums[mid]==target) return mid;
            if(nums[mid]<target){
                s=mid+1;
            }
            if(nums[mid]>target){
                l=mid-1;
            }
            mid = s+(l-s)/2;
        }
        return -1;
    }
};