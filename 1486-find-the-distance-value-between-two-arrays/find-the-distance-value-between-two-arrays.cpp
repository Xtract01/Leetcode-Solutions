class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans = 0;
        int n = arr1.size();
        int m = arr2.size();
        for(int i=0 ;i<n ; i++){
            bool isValid = true;
            for(int j=0;j<m;j++){
                if(abs(arr1[i] - arr2[j]) <= d){
                    isValid=false;
                    break;
                }
            }
            if(isValid) ans++;
        }
        return ans;
    }
};