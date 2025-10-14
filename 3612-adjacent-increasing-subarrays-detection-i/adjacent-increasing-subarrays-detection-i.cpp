class Solution {
public:
    bool isStrictlyIncreasing(vector<int> &arr , int start , int k ){
        int n = arr.size();
        for(int i=start +1;i<start + k;i++){
            if(arr[i-1]>=arr[i]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
       if (n < 2 * k) return false;
        int count = 0;
        for (int i = 0; i <= n - 2 * k; i++) {
            if (isStrictlyIncreasing(nums, i, k) && isStrictlyIncreasing(nums, i + k, k)) {
                return true;
            }
        }
        return false;
    }
};