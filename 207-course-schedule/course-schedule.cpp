class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> inDegree(numCourses,0);
        for(vector<int> &v : prerequisites){
            int u = v[0];
            int x = v[1];
            adj[u].push_back(x);
            inDegree[x]++;
        }
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++){
            if(inDegree[i]==0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(int &el:adj[node]){
                inDegree[el]--;
                if(inDegree[el]==0) q.push(el);
            }
        }
        return (cnt == numCourses);
    }
};