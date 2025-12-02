class Solution {
public:
    int M = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int , long long> mp;
        for(auto &point: points){
            int y = point[1];
            mp[y]++;
        }
        long long result = 0;   
        long long prevHorizontalLines = 0;
        for(auto &it:mp){
            long long count = it.second;
            long long HorizontalLines = count * (count-1) /2;
            result += HorizontalLines * prevHorizontalLines;
            prevHorizontalLines += HorizontalLines;
        }
        return result % M;
    }
};