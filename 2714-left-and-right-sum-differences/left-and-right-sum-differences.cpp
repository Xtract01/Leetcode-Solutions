class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n,0) , sufSum(n,0),res(n);
        for(int i=1 ; i<n ; i++){
            preSum[i] = preSum[i-1]+nums[i-1];
        }
        for(int i=n-2 ; i>=0 ; i--){
            sufSum[i] = sufSum[i+1]+nums[i+1];
        }
        for(int i=0 ; i<n ; i++){
            res[i] = abs(preSum[i]-sufSum[i]);
        }
        return res;
    }
};