class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int l=0,r=0;
        vector<int> minIdxTill(n,INT_MAX);
        int currSum = 0;
        int bestMinLen = INT_MAX;
        int res = INT_MAX;
        while(r<n){
            currSum+=arr[r];
            while(currSum>target){
                currSum-=arr[l];
                l++;
            }
            if(currSum==target){
                int len = r-l+1;
                if(l>0 && minIdxTill[l-1]!=INT_MAX){
                    res = min(res,len+minIdxTill[l-1]);
                }
                bestMinLen = min(bestMinLen,len); 
            }
            minIdxTill[r] = bestMinLen;
            r++;
        }
        return res == INT_MAX ? -1 : res;
    }
};