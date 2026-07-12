class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0 ; i<n  ;i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j]==0) {
                    q.push({0,{i,j}});
                    vis[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int dist = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
            for(vector<int> &vec: dir){
                int new_i=i+vec[0];
                int new_j=j+vec[1];
                if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && vis[new_i][new_j]==-1){
                    vis[new_i][new_j] = dist+1;
                    q.push({dist+1,{new_i,new_j}});
                }
            }
        }
        return vis;

    }
};