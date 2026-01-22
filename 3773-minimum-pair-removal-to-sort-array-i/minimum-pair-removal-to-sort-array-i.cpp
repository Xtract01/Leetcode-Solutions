class Solution {
public:
    int minPairSums(vector<int> &nums){
        int minSum = INT_MAX;
        int idx = -1;
        for(int i=0 ; i<nums.size()-1 ; i++){
            if(nums[i]+nums[i+1]<minSum){
                idx = i;
                minSum = nums[i]+nums[i+1];
            }
        }
        return idx;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int oprations = 0;
        while(!is_sorted(begin(nums),end(nums))){
            int index = minPairSums(nums);
            nums[index] += nums[index+1]; 
            nums.erase(begin(nums) + index + 1);
            oprations++;
        }
        return oprations;
    }
};