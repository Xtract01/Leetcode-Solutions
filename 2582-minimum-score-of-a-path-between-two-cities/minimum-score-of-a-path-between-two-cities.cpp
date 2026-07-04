class Solution {
public:
    void dfs(int node , int &result,unordered_map<int,vector<pair<int,int>>> &adj,vector<bool> & vis){
        vis[node] = true;
        for(auto ngbr:adj[node]){
            int nbr = ngbr.first;
            int dist = ngbr.second;
            result = min(result,dist);
            if(!vis[nbr]) dfs(nbr,result,adj,vis);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int> &vec:roads){
            int u = vec[0];
            int v = vec[1];
            int d = vec[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        vector<bool> vis(n,false);
        int result = INT_MAX;
        dfs(1,result,adj,vis);
        return result;
    }
};