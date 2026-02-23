class Solution {
public:
    bool isPossible(vector<int>& nums, int k , int maxSum , int n){
        int sum = nums[0], split = 1;
        for(int i=1 ; i<n ; i++){
            if(nums[i]+sum <= maxSum) sum+=nums[i];
            else{
                sum = nums[i];
                split++;
            }
        }
        return split <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isPossible(nums,k,mid,n)) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};