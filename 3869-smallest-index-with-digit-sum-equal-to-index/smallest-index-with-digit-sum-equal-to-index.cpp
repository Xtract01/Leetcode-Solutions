class Solution {
public:
    int sumOfDigits(int n){
        int temp = n;
        int sum = 0;
        while(temp > 0){
            sum+= temp%10;
            temp/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            if(sumOfDigits(nums[i])==i) return i;
        }
        return -1;

    }
};