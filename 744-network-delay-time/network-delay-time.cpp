class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int> &vec: times){
            int u = vec[0];
            int v = vec[1];
            int t = vec[2];
            adj[u].push_back({v,t});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});
        dist[k] = 0;
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int node = it.second;
            int time  = it.first;
            if (time > dist[node]) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                if(time + edgeW < dist[adjNode]){
                    dist[adjNode] = time + edgeW;
                    q.push({dist[adjNode],adjNode});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return (ans == INT_MAX) ? -1 : ans;
    }
};