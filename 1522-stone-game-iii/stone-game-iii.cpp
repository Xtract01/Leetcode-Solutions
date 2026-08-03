class Solution {
public:
    int t[50005];
    int helper(int i,int n, vector<int>& stoneValue ){
        if(i>=n) return 0;
        if(t[i]!=-1) return t[i];
        int score = 0;
        int res = INT_MIN;
        for(int x=0 ; x<3 ; x++){
            if(i+x<n){
                score += stoneValue[i+x];
                res = max(res,score-helper(i+x+1,n,stoneValue));
            }
        }
        return t[i]=res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(t,-1,sizeof(t));
        int n = stoneValue.size();
        int finalDiff = helper(0,n,stoneValue);
        if(finalDiff<0) return "Bob";
        else if(finalDiff>0) return "Alice";
        else return "Tie";
    }
};