class Solution {
public:
    vector<bool> isPrime;
    void buildSieve(int maxEl){
        isPrime.resize(maxEl+1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i*i<=maxEl ; i++){
            if(isPrime[i]){
                for(int multiple = i*i ; multiple<=maxEl ; multiple+=i ){
                    isPrime[multiple] = false;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        int maxEl = 0;
        int steps = 0;
        for(int i=0 ; i<n ; i++){
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl , nums[i]);
        }
        buildSieve(maxEl);
        queue<int> q;
        vector<bool>vis(n,false);
        q.push(0);
        vis[0] = true;
        unordered_set<int> seen;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front();
                q.pop();
                if(i==n-1) return steps;
                if(i-1>=0 && !vis[i-1]){
                    q.push(i-1);
                    vis[i-1] = true;
                }
                if(i+1<=n && !vis[i+1]){
                    q.push(i+1);
                    vis[i+1] = true;
                }
                if(!isPrime[nums[i]] || seen.count(nums[i])) continue;
                for(int mul = nums[i] ; mul<=maxEl ; mul+=nums[i]){
                    if(!mp.contains(mul)) continue;
                    for(int &j:mp[mul]){
                        if(!vis[j]){
                            q.push(j);
                            vis[j] = true;
                        }
                    }
                }
                seen.insert(nums[i]);
            }
            steps++;
        }
        return steps;
    }
};