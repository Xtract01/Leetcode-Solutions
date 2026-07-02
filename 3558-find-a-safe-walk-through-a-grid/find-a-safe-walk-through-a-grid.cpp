class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m= grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> minCost(m,vector<int>(n,INT_MAX));
        deque<pair<int,int>> de;
        de.push_front({0,0});
        minCost[0][0] = grid[0][0];
        while(!de.empty()){
            int r = de.front().first;
            int c = de.front().second;
            de.pop_front();
            if(r==m-1 && c==n-1) return minCost[r][c] < health;
            for(vector<int> &v : dir){
                int new_r = r + v[0];
                int new_c = c + v[1];
                if(new_r>=0 && new_r<m && new_c>=0 && new_c<n){
                    int cost = grid[new_r][new_c];
                    if(minCost[r][c] + cost < minCost[new_r][new_c]){
                        minCost[new_r][new_c] = minCost[r][c] + cost;
                        if(cost==0){
                            de.push_front({new_r,new_c});
                        }
                        else de.push_back({new_r,new_c});
                    }
                }
            }
        }
        return minCost[m-1][n-1]<health;
    }
};