class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;
    bool solve(int ind , int i, int j ,vector<vector<char>>& board,string &word){
        if(ind == word.length()) return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$'||board[i][j]!=word[ind]) return false;
        char temp = board[i][j];
        board[i][j] = '$';
        for(vector<int> &d : dir){
            int new_i  = i + d[0];
            int new_j = j + d[1];
            if(solve(ind+1,new_i,new_j,board,word)) return true;
        }
        board[i][j] = temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i =0 ; i<m ; i++){
            for(int j=0;j<n ; j++){
                if(board[i][j]==word[0] && solve(0,i,j,board,word)) return true;
            }
        }
        return false;
    }
};