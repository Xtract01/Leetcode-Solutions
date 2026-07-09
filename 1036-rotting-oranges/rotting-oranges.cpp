class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int i , int j ,vector<vector<int>>& grid,vector<vector<int>> &mat){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && mat[i][j]!=2 && grid[i][j]!=0) return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mat(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    mat[i][j] = 2;
                }
            }
        }
        int res = 0;
        while(!q.empty()){
            int time = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            for(vector<int> &v : dir){
                int new_i = i+v[0];
                int new_j = j+v[1];
                int new_ti = time+1;
                if(check(new_i,new_j,grid,mat)){
                    res = max(res,new_ti);
                    mat[new_i][new_j] = 2;
                    q.push({new_ti,{new_i,new_j}});
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==1 && mat[i][j]!=2){
                    return -1;
                }
            }
        }
        return res;
    }
};