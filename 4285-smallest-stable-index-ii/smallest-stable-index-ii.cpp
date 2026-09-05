class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxPre(n) , minSuf(n);
        int curr = nums[0];
        maxPre[0] = curr;
        for(int i=1; i<n ; i++){
            if(nums[i]>curr) curr = nums[i];
            maxPre[i] = curr;
        }
        curr = nums[n-1];
        minSuf[n-1] = curr;
        for(int i=n-2 ; i>=0  ; i--){
            if(nums[i]<curr) curr = nums[i];
            minSuf[i] = curr;
        }
        for(int i=0 ; i<n ; i++){
            if(maxPre[i]-minSuf[i] <=k) return i;
        }
        return -1;
    }
};