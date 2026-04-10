class Solution {
public:
    bool isValid(vector<vector<char>>& board,int i , int j , char d){
        for(int ind=0 ; ind<9 ; ind++){
            if(board[ind][j]==d) return false;
            if(board[i][ind]==d) return false;
        }
        int start_i = i/3*3;
        int start_j = j/3*3;
        for(int k=0 ; k<3 ; k++ ){
            for(int l = 0;l<3 ; l++){
                if(board[start_i+k][start_j+l]==d) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(board[i][j]=='.'){
                    for(int d = '1'; d<='9';d++){
                        if(isValid(board,i,j,d)){
                            board[i][j] = d;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};