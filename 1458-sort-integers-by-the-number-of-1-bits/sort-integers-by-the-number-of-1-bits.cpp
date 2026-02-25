class Solution {
public: 
    static bool customComparator(int a,int b){
        if(__builtin_popcount(a)==__builtin_popcount(b)){
            return a<b;
        }
        else return __builtin_popcount(a)<__builtin_popcount(b);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),customComparator);
        return arr;
    }
};