class Solution {
public:
    bool isValid(vector<string> &board, int r , int c, int n){
        for(int i=r-1 ; i>=0 ; i--) {
            if(board[i][c]=='Q') return false;
        }
        for(int i=r-1 , j=c-1 ; i>=0 && j>=0 ; i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=r-1 , j=c+1 ; i>=0 && j<n; i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(int row, int n, vector<string> &temp,vector<vector<string>> &board){
        if(row>=n){
            board.push_back(temp);
            return;
        }
        for(int i=0 ; i<n ; i++){
            if(isValid(temp,row,i,n)){
                temp[row][i] = 'Q';
                solve(row+1,n,temp,board);
                temp[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>board(n,string(n,'.'));
        solve(0,n,board,res);
        return res;
    }
};