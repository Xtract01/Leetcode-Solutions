class Solution {
public:
    
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int> &vec:roads){
            int u = vec[0];
            int v = vec[1];
            int d = vec[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        vector<bool> vis(n+1,false);
        int result = INT_MAX;
        queue<int> q;
        vis[1] = true;
        q.push(1);
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto ngbr:adj[node]){
                int nbr = ngbr.first;
                int dist = ngbr.second;
                result = min(dist,result);
                if(!vis[nbr]){
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return result;
    }
};