class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int res = INT_MIN;
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n; j++){
                if(colors[i]!=colors[j]){
                    res = max(res,abs(i-j));
                }
            }
        }
        return res;
    }
};