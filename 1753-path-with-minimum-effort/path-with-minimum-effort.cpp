class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
> pq;

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==m-1) return dis;
            for(vector<int> &v: dir){
                int new_r = r+v[0];
                int new_c = c+v[1];
                if(new_r>=0 && new_r<n && new_c>=0 && new_c<m  ){
                    int newEffort = max(abs(heights[r][c]-heights[new_r][new_c]),dis);
                    if(newEffort < dist[new_r][new_c]){
                        dist[new_r][new_c] = newEffort;
                        pq.push({newEffort,{new_r,new_c}});
                    }
                }
            }
        }
        return 0;

    }
};