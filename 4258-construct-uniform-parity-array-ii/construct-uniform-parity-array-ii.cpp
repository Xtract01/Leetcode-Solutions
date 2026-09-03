class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false,hasEven = false;
        int minOdd = INT_MAX;
        for(int x:nums1){
            if(x%2!=0){
                hasOdd = true;
                minOdd = min(minOdd,x);
            }
            else hasEven = true;
        }
        if(!hasEven || !hasOdd) return true;
        for(int x:nums1){
            if(x%2==0 && x<minOdd) return false;
        }
        return true;
    }
};