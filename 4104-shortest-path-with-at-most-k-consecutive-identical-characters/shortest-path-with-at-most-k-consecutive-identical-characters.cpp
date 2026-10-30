class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges){
            int u= e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
        }
        const long long INF  = 4e18;
        vector<vector<long long>> dist(n,vector<long long>(k+1,INF));
        priority_queue<vector<long long>,vector<vector<long long>> , greater<vector<long long>>> pq;
        dist[0][1] = 0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto el = pq.top();
            pq.pop();
            long long cost = el[0];
            int u = el[1];
            int cnt = el[2];

            if(cost>dist[u][cnt]) continue;

            for(auto &it:adj[u]){
                int v = it.first;
                int w = it.second;
                int newCnt ;
                if(labels[u]==labels[v]) newCnt = cnt+1;
                else newCnt = 1;
                if(newCnt>k) continue;
                long long newCost = cost + w;
                if(newCost < dist[v][newCnt]){
                    dist[v][newCnt] = newCost;
                    pq.push({newCost,v,newCnt});
                }
            }
        }
            long long ans = INF;
            for(int i=1 ; i<=k ; i++){
                ans = min(ans,dist[n-1][i]);
            }
            return ans == INF ? -1:ans;
    }
};