class Solution {
public:
    typedef long long ll;
    pair<int,int> firstAndSecondLarge(vector<int> nums){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return {nums[0],nums[1]};
    }
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        int m = units[0].size();
        ll ans = 0;
        if(m==1){
            for(auto it:units){
                ans += it[0];
            }
            return ans;
        }
        ll sumOfSecond = 0;
        int minOfAllFirst = INT_MAX;
        int minSecond = INT_MAX;
        for(int i=0 ; i<n ; i++){
            auto [a,b] = firstAndSecondLarge(units[i]);
            sumOfSecond+=b;
            minOfAllFirst = min(minOfAllFirst,a);
            minSecond = min(minSecond,b);
        }
        return sumOfSecond - minSecond + minOfAllFirst;
    }
};