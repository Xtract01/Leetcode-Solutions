class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cntOnes = 0;
        for(auto &el : nums) {
            if(el==1) cntOnes++;
        }
        if(cntOnes>0) return n-cntOnes;
        int minStepsTo1 = INT_MAX;
        for(int i =0 ;i<n ; i++){
            int GCD = nums[i];
            for(int j = i+1 ; j<n ; j++){
                GCD = gcd(GCD,nums[j]);
                if(GCD==1){
                    minStepsTo1 = min(minStepsTo1,j-i);
                    break;
                }
            }
        }
        if(minStepsTo1 == INT_MAX) return -1;
        return minStepsTo1 + (n-1);
    }
};