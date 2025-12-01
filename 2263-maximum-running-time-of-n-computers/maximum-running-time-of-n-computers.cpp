class Solution {
public:
    typedef long long ll;
    bool possible(vector<int>& batteries , ll mid , int n){
        ll target =  n*mid;
        ll sum = 0;
        for(int i=0 ; i< batteries.size();i++){
            sum+= min(1LL*batteries[i],mid);
        }
        if(sum >= target) return true;
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = *min_element(begin(batteries),end(batteries));
        ll sum = 0;
        for(auto &minutes:batteries){
            sum+=minutes;
        }
        ll r = sum/n;
        ll result = 0;
        while(l<=r){
            ll mid = l + (r-l)/2;
            if(possible(batteries,mid,n)){
                result = mid;
                l = mid+1;
            }
            else r =  mid-1;
        }
        return result;
    }
};