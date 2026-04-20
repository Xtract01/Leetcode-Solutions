class Solution {
public:
    int findPar(vector<int> &par , int x){
        if(par[x]==x) return x;
        return par[x] = findPar(par,par[x]);
    }
    bool unionSet(vector<int> &par , vector<int>& rnk , int u , int v){
        u = findPar(par,u);
        v = findPar(par,v);
        if(u==v) return true;
        else if(rnk[u]<rnk[v]){
            par[u] = v;
        }
        else if(rnk[u]>rnk[v]){
            par[v] = u;
        }
        else {
            rnk[u]++;
            par[v] = u;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n + 1);
        vector<int> rnk(n + 1, 0);
        for(int i= 1 ;i<=n ; i++){
            par[i] = i;
        }
        for(int i=0; i<n ;i++){
            if(unionSet(par,rnk,edges[i][0],edges[i][1])) return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};