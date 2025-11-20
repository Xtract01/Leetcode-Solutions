class DisjointSet{
public:
    vector<int> rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i = 0 ;i<=n ; i++){
            parent[i] = i;
        }
    }
    int findPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank (int u , int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u == ulp_v) return;
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
    void unionBySize (int u , int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
private:
    bool isValid(int newr , int newc , int n){
        return newr>=0 && newr<n && newc>=0 && newc<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet dis(n*n);
        for(int i = 0 ;i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j]==0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                for(int ind = 0; ind<4;ind++){
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        int nodeNo = i * n + j;
                        int adjNodeNo = newr * n+ newc;
                        dis.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        int mx = 0;
        for(int i = 0 ; i< n ; i++){
            for(int j= 0 ; j< n ; j++){
                if(grid[i][j]==1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                set<int> components;
                for(int ind = 0; ind<4;ind++){
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];
                    if(isValid(newr,newc,n) ){
                        if(grid[newr][newc]==1){
                            components.insert(dis.findPar(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it:components){
                    sizeTotal += dis.size[it];
                }
                mx = max(mx,sizeTotal+1);
            }
        }
        for(int i = 0 ; i< n*n ; i++){
            mx = max(mx,dis.size[dis.findPar(i)]);
        }
        return mx;
    }
};