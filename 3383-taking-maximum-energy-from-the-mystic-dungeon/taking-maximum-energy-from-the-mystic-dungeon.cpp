class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> prefixSum(n,0);
        prefixSum[n-1] = energy[n-1];
        for(int i = n-1 ; i>=0 ; i--){
            if(i+k<n){
                prefixSum[i]= energy[i]+ prefixSum[i+k];
            }
            else prefixSum[i] = energy[i];
        }
        sort(prefixSum.begin(),prefixSum.end());
        return prefixSum[n-1];
    }
};