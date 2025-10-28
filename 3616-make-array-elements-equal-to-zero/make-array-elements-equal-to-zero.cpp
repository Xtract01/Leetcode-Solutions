class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int curr =0;
        int s = accumulate(begin(nums),end(nums),0);
        for(int i=0;i<n;i++){
            curr+=nums[i];
            int left = curr;
            int right= s - left;
            if(nums[i]!=0) continue;
            if(left==right) result+=2;
            else if(abs(left-right)==1) result+=1;

        }
        return result;
    }
};