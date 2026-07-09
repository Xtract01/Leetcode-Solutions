class DSU{
public:
    vector<int> rank,parent;
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0 ; i<=n ; i++) parent[i] = i;
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU ds(n);
        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i-1] <= maxDiff)
                ds.unionByRank(i, i-1);
        }
        int q = queries.size();
        vector<bool> res(q);
        for(int i=0 ; i<q ; i++){
            int u = queries[i][0];
            int v= queries[i][1];
            if(ds.findUPar(u)==ds.findUPar(v)) res[i] = true;
            else res[i] = false;
        }
        return res;
    }
};