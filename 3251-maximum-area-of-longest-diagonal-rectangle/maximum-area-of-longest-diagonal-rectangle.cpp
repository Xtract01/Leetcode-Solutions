class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal = -1;
        int idx = -1;
        for(int i = 0 ; i<dimensions.size();i++){
            if(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1] > maxDiagonal){
                maxDiagonal = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];
                idx = i;
            }
            else if(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1] == maxDiagonal){
                idx = (dimensions[idx][1]*dimensions[idx][0] < dimensions[i][0]*dimensions[i][1] ) ? i :idx; 
            }
        }
        return dimensions[idx][1]*dimensions[idx][0];
    }
};