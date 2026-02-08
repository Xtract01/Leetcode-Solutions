class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cntZeroes = 0;
        int i=0 , j=0 , len = 0 , maxLen = 0;
        while(j<n){
            if(nums[j]==0) cntZeroes++;
            if(cntZeroes>k){
                if(nums[i]==0) cntZeroes--;
                i++;
            }
            else {
                len = j-i+1;
                maxLen = max(len,maxLen);
            }
            j++;
        }
        return maxLen;
    }
};