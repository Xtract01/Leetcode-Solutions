class Solution {
public:
    typedef long long ll;
    const ll INF = 4e18;
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue<tuple<ll,int,int,int>,vector<tuple<ll,int,int,int>>,greater<tuple<ll,int,int,int>>> pq;
        vector<vector<vector<ll>>> dist(m, vector<vector<ll>>(n, vector<ll>(2, INF)));
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        vector<vector<int>> vis(m,vector<int>(n,0));
        dist[0][0][1] = 1;          
        pq.push({1, 0, 0, 1});
        while(!pq.empty()){
           auto [cost, x, y, parity] = pq.top();
            pq.pop();
            if (cost != dist[x][y][parity]) continue;
            if (x == m-1 && y == n-1)
                return cost;

            int nextParity = parity ^ 1;
            if (cost + penalty[x][y] < dist[x][y][nextParity]) {
                dist[x][y][nextParity] = cost + penalty[x][y];
                pq.push({dist[x][y][nextParity], x, y, nextParity});
            }
            for(int k=0 ; k<4 ; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                ll add = 1LL * (nx + 1) * (ny + 1);
                bool follows = (parity == 1 && (k == 0 || k == 2)) || (parity == 0 && (k == 1 || k == 3));
                if (!follows)
                    add += penalty[x][y]; 
                    if (cost + add < dist[nx][ny][nextParity]) {
                    dist[nx][ny][nextParity] = cost + add;
                    pq.push({dist[nx][ny][nextParity], nx, ny, nextParity});
                }  
            }
            
        }
        return -1;
    }
};