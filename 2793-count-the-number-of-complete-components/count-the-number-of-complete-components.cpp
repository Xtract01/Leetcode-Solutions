class Solution {
public:
    void bfs(int i, unordered_map<int,vector<int>> &adj, vector<bool> &vis, int &v , int &e){
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            v++;
            e+=adj[curr].size();
            for(int ngbr:adj[curr]){
                if(!vis[ngbr]) {
                    vis[ngbr] = true;
                    q.push(ngbr);
                }
                
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        int res = 0;
        for(vector<int> &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                int v=0 ;
                int e=0;
                bfs(i,adj,vis,v,e);
                if(v*(v-1)==e) res++;
            }
        }
        return res;

    }
};