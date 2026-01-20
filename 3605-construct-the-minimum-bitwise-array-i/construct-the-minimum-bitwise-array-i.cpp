class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i=0 ; i<n ; i++){
            bool flag = false;
            for(int x = 0 ; x<=nums[i]-1 ; x++){
                if((x | (x+1))==nums[i]){
                    flag = true;
                    result.push_back(x);
                    break;
                }
            }
            if(!flag) result.push_back(-1);
        }
        return result;
    }
};