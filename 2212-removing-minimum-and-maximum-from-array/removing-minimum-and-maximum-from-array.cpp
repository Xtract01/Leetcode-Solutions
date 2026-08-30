class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = INT_MIN, maxIdx = -1;
        int mini = INT_MAX , minIdx = -1;
        int n = nums.size();
        if(n==1) return 1;
        for(int i=0 ; i<n ; i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                maxIdx = i;
            }
            if(nums[i]<mini){
                mini = nums[i];
                minIdx = i;
            }
        }
        int leftIdx = min(minIdx,maxIdx);
        int rightIdx = max(maxIdx,minIdx);

        int bothLeft = rightIdx+1;
        int bothRight = n-leftIdx ;
        int different = leftIdx+1 + n-rightIdx;
        return min({bothLeft,bothRight,different});
    }
};