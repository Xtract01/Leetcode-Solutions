class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k , int day){
        int n = bloomDay.size();
        int cnt = 0;
        int bouquets = 0;
        for(int i=0 ; i<n ;i++){
            if(bloomDay[i]<=day) cnt++;
            else {
                bouquets += (cnt/k);
                cnt = 0; 
            }
        }
        bouquets += (cnt/k);
        return (bouquets >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k){
        int n = bloomDay.size();
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(isPossible(bloomDay,m,k,mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};