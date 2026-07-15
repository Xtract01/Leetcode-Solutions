class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        vector<vector<int>>dist (n,vector<int>(m,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> pq;
        dist[0][0] = 1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();
            for(vector<int> &dr : dir){
                int new_r = row + dr[0];
                int new_c = col + dr[1];
                if(new_r<0 || new_r>=n || new_c<0 || new_c>=m || grid[new_r][new_c]==1) continue;
                if(dist[new_r][new_c] > d+1){
                    dist[new_r][new_c] = d+1;
                    pq.push({d+1,{new_r,new_c}});
                }
            }
        }
        return dist[n-1][m-1]==INT_MAX?-1:dist[n-1][m-1];

    }
};