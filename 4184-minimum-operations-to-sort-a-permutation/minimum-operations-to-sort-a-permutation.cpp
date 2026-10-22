class Solution {
public:
    bool checkSortedRotated(vector<int> &nums){
        int n = nums.size();
        int peak = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]>nums[(i+1)%n]) peak++;
        }
        return peak<=1;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;
        int ans = INT_MAX;
        if(checkSortedRotated(nums)){
            for(int i=0 ;i<n ; i++){
                if(nums[i]==0) ans = min(i, ans) ;
            }
        }
        reverse(nums.begin(),nums.end());
        if(checkSortedRotated(nums)){
            for(int i=0 ;i<n ; i++){
                if(nums[i]==0)  ans = min(1+i , ans);
            }
        }
        if(checkSortedRotated(nums)){
            int z = -1;
            for(int i=0 ; i<n ; i++) if(nums[i]==0) z= i;
            int r=(n-z)%n;
            if(r>=1 && r<n) ans = min(ans,r+1);
        }
        reverse(nums.begin(),nums.end());
        if(checkSortedRotated(nums)){
            int z = -1;
            for(int i=0 ; i<n ; i++) if(nums[i]==0) z= i;
            int r=(n-z)%n;
            if(r>=1 && r<n) ans = min(ans,r+2);
        }
        return ans==INT_MAX?-1:ans;
    }
};