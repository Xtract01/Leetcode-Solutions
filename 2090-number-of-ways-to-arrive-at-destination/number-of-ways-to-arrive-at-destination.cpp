class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        const int MOD = 1e9+7;
        for(vector<int> &road:roads){
            int u = road[0];
            int v = road[1];
            int wt= road[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<long long> dist(n, LLONG_MAX);
vector<int> ways(n, 0);

priority_queue<
    pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>
> pq;

dist[0] = 0;
ways[0] = 1;
pq.push({0,0});

while(!pq.empty()) {
    auto [wt, node] = pq.top();
    pq.pop();

    if(wt > dist[node]) continue;

    for(auto it : adj[node]) {
        int ngbr = it.first;
        int dis = it.second;

        if(wt + dis < dist[ngbr]) {
            dist[ngbr] = wt + dis;
            ways[ngbr] = ways[node];
            pq.push({dist[ngbr], ngbr});
        }
        else if(wt + dis == dist[ngbr]) {
            ways[ngbr] = (ways[ngbr] + ways[node]) % MOD;
        }
    }
}
        return ways[n-1];

    }
};