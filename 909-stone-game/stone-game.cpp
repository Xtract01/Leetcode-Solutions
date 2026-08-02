class Solution {
public:
    int t[501][501];
    int helper(int i , int j ,vector<int>& piles ){
        if(i>j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int take_i = piles[i] + min(helper(i+2,j,piles),helper(i+1,j-1,piles));
        int take_j = piles[j] + min(helper(i+1,j-1,piles),helper(i,j-2,piles));

        return t[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        int aliceScore = helper(0,piles.size()-1,piles);
        int sum = accumulate(piles.begin(),piles.end(),0);
        return aliceScore >= sum/2;
    }
};