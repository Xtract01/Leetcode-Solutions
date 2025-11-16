class DisjointSet {
    vector<int> rank,parent;
  public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0 ; i<=n ; i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u , int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        DisjointSet dis(n);
        for(vector<int> &v: connections){
            dis.unionByRank(v[0],v[1]);
        }
        unordered_set<int> st;
        for(int i = 0 ;i<n ; i++){
            st.insert(dis.findParent(i));
        }
        return st.size()-1;
    }
};