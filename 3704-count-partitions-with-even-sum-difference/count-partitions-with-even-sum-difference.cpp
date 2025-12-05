class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> prefixSum(n,0);
        vector<int> suffixSum(n,0);
        prefixSum[0] = nums[0];
        suffixSum[n-1] = nums[n-1];
        for(int i=1 ; i<n ; i++){
            prefixSum[i] = nums[i]+prefixSum[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffixSum[i] = nums[i] + suffixSum[i+1];
        }
        for(int i=0 ; i< n-1 ;i++){
            if(abs(prefixSum[i]-suffixSum[i+1])%2 == 0) ans++;
        }
        return ans;
    }
};