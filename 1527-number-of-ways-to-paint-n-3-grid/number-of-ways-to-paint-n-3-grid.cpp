class Solution {
public:
    int M = 1e9 + 7;
    string states[12] = {"RYG","RGY","RYR","RGR","YRG","YGR","YGY","YRY","GRY","GYR","GRG","GYG"};
    vector<vector<int>> t;
    int solve(int n, int prev){
        if(n==0) return 1;
        if(t[n][prev]!=-1) return t[n][prev];
        int ways = 0;
        string last = states[prev];
        for(int curr=0; curr<12 ; curr++){
            if(curr==prev) continue;
            string currPattern = states[curr];
            bool conflict = false;
            for(int i=0 ; i< 3 ; i++){
                if(currPattern[i] == last[i]){
                    conflict = true;
                    break;
                }
            }
            if(!conflict) {
                ways = (ways + solve(n-1,curr)) % M;
            }
            
        }
        return t[n][prev]=ways;

    }
    int numOfWays(int n) {
        t.resize(n,vector<int>(12,-1));
        int result = 0;
        for(int i=0 ; i<12;i++){
            result=(result + solve(n-1,i)) %M;
        }
        return result;
    }
};