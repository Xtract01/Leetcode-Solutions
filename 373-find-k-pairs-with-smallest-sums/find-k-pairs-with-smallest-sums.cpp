class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P,vector<P>,greater<P>> minHeap;
        vector<vector<int>> ans;
        set<pair<int,int>> vis;
        minHeap.push({nums1[0]+nums2[0],{0,0}});
        while(k-- && !minHeap.empty()){
            int i = minHeap.top().second.first;
            int j = minHeap.top().second.second;
            ans.push_back({nums1[i],nums2[j]});
            minHeap.pop();
            if(i + 1 < nums1.size() && !vis.count({i+1,j})) {
                vis.insert({i+1,j});
                minHeap.push({nums1[i+1] + nums2[j], {i+1,j}});
            }

            if(j + 1 < nums2.size() && !vis.count({i,j+1})) {
                vis.insert({i,j+1});
                minHeap.push({nums1[i] + nums2[j+1], {i,j+1}});
            }
        }
        return ans;

    }
};