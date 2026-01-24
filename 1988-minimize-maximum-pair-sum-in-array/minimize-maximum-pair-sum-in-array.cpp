class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n -1;
        int res = 0;
        while(i<n){
            res = max(res,nums[i]+nums[j]);
            i++;
            j--;
        }
        return res;
    }
};