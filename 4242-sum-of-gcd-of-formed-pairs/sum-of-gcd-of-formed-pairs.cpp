class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int currMax = INT_MIN;
        vector<int> preGCD(n);
        for(int i=0 ; i<n ; i++){
            currMax = max(currMax,nums[i]);
            preGCD[i] = gcd(currMax,nums[i]);
        }
        sort(preGCD.begin(),preGCD.end());
        long long sum = 0;
        int i = 0 , j = n-1;
        while(i<j){
            sum+= gcd(preGCD[i],preGCD[j]);
            i++,j--;
        }
        return sum;
    }
};