class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });
        int prevEnd = intervals[0][1];
        int ans = 1;
        for(int i=1 ; i<n ; i++){
            if(intervals[i][0]>=prevEnd){
                prevEnd = intervals[i][1];
                ans++;
            }
        }
        return n-ans;
    }
};