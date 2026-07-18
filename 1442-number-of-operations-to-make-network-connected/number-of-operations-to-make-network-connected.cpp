class DSU{
public:
    vector<int> rank, parent;
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0 ; i<n ; i++) parent[i] = i;
    }
    int findUpar(int u){
        if(parent[u]==u) return u;
        return parent[u] = findUpar(parent[u]);
    }
    void unionByRank(int u, int v){
        int pu = findUpar(u);
        int pv = findUpar(v);
        if(pv==pu) return;
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else if(rank[pv]>rank[pu]) parent[pu]=pv;
        else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        for(vector<int> &v:connections){
            dsu.unionByRank(v[0],v[1]);
        }
        if (connections.size() < n - 1) return -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.findUpar(i) == i)
                ans++;
        }
        return ans-1;
    }
};