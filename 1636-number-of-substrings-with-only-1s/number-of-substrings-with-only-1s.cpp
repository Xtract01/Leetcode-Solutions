class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        map<int,int> mp;
        vector<int> consecOnes(n,0);
        int countOnes = 0;
        int ans = 0;
        const long long MOD = 1'000'000'007;
        for(int i = 0; i<n ;i++){
            if(s[i]=='1'){
                countOnes++;
                consecOnes[i] = countOnes;
            }
            else countOnes = 0;
        }
        for(int i = 0 ; i<n ; i++){
            mp[consecOnes[i]]++;
        }
        for(auto &el : mp){
            long long k = el.first;
            long long freq = el.second;
            ans = (ans + k * freq) % MOD;
        }
        return ans ;

    }
};