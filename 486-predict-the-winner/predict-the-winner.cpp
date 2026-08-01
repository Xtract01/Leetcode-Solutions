class Solution {
public:
    int t[21][21];
    int helper(int i, int j ,vector<int>& nums ){
        if(i>j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int take_i = nums[i] + min(helper(i+2,j,nums),helper(i+1,j-1,nums));
        int take_j = nums[j] + min(helper(i+1,j-1,nums),helper(i,j-2,nums));

        return t[i][j]=max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int sum = accumulate(nums.begin(),nums.end(),0);
        return helper(0,nums.size()-1,nums)>=sum-helper(0,nums.size()-1,nums);
    }
};