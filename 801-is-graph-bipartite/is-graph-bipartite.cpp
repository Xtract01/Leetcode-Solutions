class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for (int i = 0; i < n; i++) {
            if (color[i] != -1) continue;

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int ngbr : graph[node]) {
                    if (color[ngbr] == -1) {
                        color[ngbr] = 1 - color[node];
                        q.push(ngbr);
                    }
                    else if (color[ngbr] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
        
    }
};