class Solution {
public:
    int dp[2001][2001];
    bool helper(int i , int n, int prevJump ,  vector<int> &stones , unordered_map<int,int> &mp){
        if(i==n-1) return true;
        if(dp[i][prevJump]!=-1) return dp[i][prevJump];
        bool result = false;
        for(int nextJump = prevJump-1 ; nextJump<= prevJump+1 ; nextJump++){
            if(nextJump >0){
                int nextStone = stones[i] + nextJump;
                if(mp.find(nextStone)!=mp.end()){
                    result = result || helper(mp[nextStone],n,nextJump,stones,mp);
                    if(result) break;
                }

            }
        }
        return dp[i][prevJump] = result;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        memset(dp,-1,sizeof dp);
        unordered_map<int,int> mp;
        for(int i=0 ;i<stones.size();i++){
            mp[stones[i]] = i;
        }
        return helper(0,stones.size(),0,stones,mp);
    }
};