class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i  =0;
        int j = 0 , n = nums.size();
        int cnt0 = 0;
        int res = 0;
        while(j<n){
            if(nums[j]==0) cnt0++;
            while(cnt0>k){
                if(nums[i]==0) cnt0--;
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};