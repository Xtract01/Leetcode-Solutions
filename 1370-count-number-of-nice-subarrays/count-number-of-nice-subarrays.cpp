class Solution {
public:
    int f(vector<int> &temp , int k){
        int n = temp.size();
        if(k<0) return 0;
        int i=0 , j= 0 , cnt = 0 , sum = 0;
        while(j<n){
            sum+=temp[j];
            while(sum>k){
                sum-=temp[i];
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i=0 ; i<n ; i++){
            if(nums[i]%2==0) temp[i] = 0;
            else temp[i] = 1;
        }
        return f(temp,k) - f(temp, k-1);
        
    }
};