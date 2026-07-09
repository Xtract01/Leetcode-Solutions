class Solution {
public:
    void dfs(int node , vector<bool> &vis ,unordered_map<int,vector<int>> &adj ){
        vis[node] = true;
        for(int ngbr:adj[node]){
            if(!vis[ngbr]){
                dfs(ngbr,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> adj;
        int n = isConnected.size();
        int m = isConnected[0].size();
        for(int i=0 ; i<n ; i++){
            for(int j = 0; j<n ; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,false);
        int res = 0;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                res++;
                dfs(i,vis,adj);
            }
        }
        return res;
    }
};