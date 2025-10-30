class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n==1) return 1;
        pair<int,int> src = {0,0};
        pair<int,int> dest = {n-1,n-1};
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
        dist[src.first][src.second] = 1;
        q.push({1,{src.first,src.second}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(vector<int>& vec : dir){
                int new_r = r + vec[0];
                int new_c = c + vec[1];
                if(new_r>=0 && new_r<n && new_c>=0 && new_c<n && grid[new_r][new_c]==0 && dis + 1 < dist[new_r][new_c]){
                    dist[new_r][new_c] = 1+dis;
                    if(new_r==dest.first && new_c==dest.second) return dis+1;
                    q.push({dis+1,{new_r,new_c}});
                }
            }
        }
        return -1;
    }
};