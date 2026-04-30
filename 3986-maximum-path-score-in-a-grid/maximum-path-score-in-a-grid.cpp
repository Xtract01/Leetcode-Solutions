class Solution {
public:
    int m , n;
    int solve(int i, int j,vector<vector<int>>& grid, int k , int cost,vector<vector<vector<int>>> &t){
        if(i>=m|| j>=n) return INT_MIN;
        int new_cost = cost + (grid[i][j]>0);
        if(new_cost>k) return INT_MIN;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(t[i][j][new_cost]!=-1) return t[i][j][new_cost];
        
        int down = solve(i+1,j,grid,k,new_cost,t);
        int right = solve(i,j+1,grid,k,new_cost,t);

        int bestNext = max(down,right);
        if(bestNext == INT_MIN) return t[i][j][new_cost] = INT_MIN;
        return t[i][j][new_cost] = grid[i][j]+bestNext;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m= grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> t(
    m+1,
    vector<vector<int>>(n+1, vector<int>(k+1, -1))
);
        int result = solve(0,0,grid,k,0,t);
        return result == INT_MIN ? -1 : result;
    }
};