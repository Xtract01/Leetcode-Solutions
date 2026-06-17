class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = nums[0];
        for(int i=1 ; i<n ;i++){
            if(i>maxJump) return false;
            maxJump = max(maxJump,i+nums[i]);
        }
        return true;
    }
};