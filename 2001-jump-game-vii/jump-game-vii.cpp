class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1]!='0') return false;
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0] = 1;
        int far = 0;
        while(!q.empty()){
            int index = q.front();
            q.pop();
            if(index==n-1) return true;
            int start = max(far+1,index+minJump);
            int end = min(n-1 , index+maxJump);
            for(int i = start; i<=end ; i++){
                if(s[i]=='0' && !vis[i]){
                    vis[i]=true;
                    q.push(i);
                }
            }
            far = max(far,end);
        }
        return false;
    }
};