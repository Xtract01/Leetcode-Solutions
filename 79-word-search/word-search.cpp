class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    bool solve(int idx ,int row , int col,string &word , vector<vector<char>> &board){
        if(board[row][col]!=word[idx]) return false;
        if(idx==word.size()-1){
            return true;
        }
        char temp= board[row][col];
        board[row][col]='$';
        for(auto &d:dir){
            int new_r = row + d[0];
            int new_c = col + d[1];
            if(new_r<board.size() && new_r>=0 && new_c<board[0].size() && new_c>=0 && board[new_r][new_c]!='$'){
                if(solve(idx+1,new_r,new_c,word,board)){
                    board[row][col] = temp;
                    return true;
                }
            }
        }
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0 ;i<n ; i++){
            for(int j=0 ;j<m ; j++){
                if(board[i][j]==word[0]){
                    if(solve(0, i, j, word, board)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};