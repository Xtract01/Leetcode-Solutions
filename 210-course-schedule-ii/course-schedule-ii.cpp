class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(vector<int> &vec : prerequisites){
            int first = vec[0];
            int sec = vec[1];
            adj[sec].push_back(first);
        }
        vector<int> in(numCourses,0);
        vector<int> topo ;
        for(int i = 0; i< numCourses ; i++){
            for(auto it: adj[i]) in[it]++;
        }
        queue<int> q;
        for(int i = 0 ; i< numCourses;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};