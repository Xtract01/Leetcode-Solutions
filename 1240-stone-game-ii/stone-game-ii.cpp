class Solution {
public:
    int t[2][101][101];
    int helper(int i,int player, int M , int n ,vector<int>& piles ){
        if(i>=n) return 0;
        if(t[player][i][M]!=-1) return t[player][i][M];
        int stones = 0;
        int res = (player==0 ? -1 :INT_MAX);
        for(int x=1 ; x<=min(n-i,2*M) ; x++){
            if(player==0){
                stones+=piles[i+x-1];
                res = max(res,stones + helper(i+x,1,max(M,x),n,piles));
            }
            else{
                res = min(res,helper(i+x,0,max(M,x),n,piles));
            }
        }
        return  t[player][i][M]=res;
    }
    int stoneGameII(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        int n = piles.size();
        return helper(0,0,1,n,piles);
    }
};