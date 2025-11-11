class Solution {
public:
    int t[101][101][601];
    int solve(vector<pair<int,int>> &counts , int i , int m ,int n){
        if(i>=counts.size() || (m==0 && n==0)) return 0;
        if(t[m][n][i] != -1) return t[m][n][i];
        int take = 0;
        if(counts[i].first <= m && counts[i].second <=n){
            take = 1+solve(counts,i+1,m-counts[i].first , n-counts[i].second);
        }
        int skip = solve(counts,i+1,m,n);
        return t[m][n][i] = max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int cntZero;
        int cntOne;
        int ans = 0;
        vector<pair<int,int>> counts;
        for(auto &str : strs){
            cntZero = 0 ;
            cntOne = 0;
            for(int i = 0 ; i< str.length(); i++){
                if(str[i] == '0') cntZero++;
                else cntOne++;
            }
            counts.push_back({cntZero,cntOne});
        }
        memset(t,-1,sizeof(t));
        return solve(counts,0,m,n);
        
    }
};