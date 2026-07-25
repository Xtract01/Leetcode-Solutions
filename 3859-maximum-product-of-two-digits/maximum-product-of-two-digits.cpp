class Solution {
public:
    vector<int> digits(int n){
        vector<int> res;
        while(n>0){
            int l = n%10;
            res.push_back(l);
            n/=10;
        }
        sort(res.begin(),res.end());
        return res;
    }
    int maxProduct(int n) {
        vector<int> allDigits = digits(n);
        int x = allDigits.size();
        return allDigits[x-1]*allDigits[x-2];
    }
};