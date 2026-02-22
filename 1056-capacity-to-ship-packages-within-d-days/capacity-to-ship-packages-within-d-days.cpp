class Solution {
public:
    int daysReq(vector<int>& weights , int n ,int maxW){
        int days = 1;
        int sumW = 0;
        for(int i = 0 ; i<n ; i++){
            if(sumW+weights[i]<=maxW){
                sumW+=weights[i];
            }
            else {
                sumW = weights[i];
                days++;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = *max_element(weights.begin(),weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(daysReq(weights,n,mid)<=days){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};