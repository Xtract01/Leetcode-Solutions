class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans (n,vector<int>(n,0));
        for(vector<int> &vec:queries){
            int a = vec[0];
            int b = vec[1];
            int c = vec[2];
            int d = vec[3];
            for(int i=a ; i<=c ;i++){
                for(int j = b; j<=d ; j++){
                    ans[i][j]++;
                }
            }
        }
        return ans;
    }
};