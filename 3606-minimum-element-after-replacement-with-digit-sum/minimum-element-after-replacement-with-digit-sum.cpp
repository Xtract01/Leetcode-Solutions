class Solution {
public:
    int sumEl ( int x){
        int ans = 0;
        while(x>0){
            ans+=x%10;
            x/=10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            nums[i] = sumEl(nums[i]);
        }
        return *min_element(nums.begin(),nums.end());
    }
};