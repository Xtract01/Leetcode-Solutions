class Solution {
public:
    typedef long long ll;
    int M = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> nonZeroCount(n,0);
        vector<ll> numberUpto(n,0);
        vector<ll> digitSumUpto(n,0), pow10(n+1,0);

        pow10[0] = 1;
        for(int i=1 ; i<=n;i++){
            pow10[i] = (pow10[i-1]*10) %M;
        }

        nonZeroCount[0] = (s[0]!='0') ? 1:0;
        for(int i=1 ; i<n ; i++){
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i-1] + ((digit!=0) ? 1:0);
        }
        numberUpto[0] = s[0]-'0';
        for(int i=1; i<n ;i++){
            int digit = s[i]-'0';
            if(digit!=0){
                numberUpto[i] = ((numberUpto[i-1] * 10) + digit) %M;
            }
            else numberUpto[i] = numberUpto[i-1];
        }
        digitSumUpto[0] = s[0]-'0';
        for(int i=1 ; i<n ; i++){
            int digit = s[i] -'0';
            digitSumUpto[i] = digitSumUpto[i-1]+digit;
        }
        int q = queries.size();
        vector<int> res(q);
        for(int i=0 ; i<q ; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            ll sum = digitSumUpto[r] - ((l==0)?0:digitSumUpto[l-1]);
            int numBefore = (l==0)?0:numberUpto[l-1];
            int k= nonZeroCount[r] - ((l==0)?0:nonZeroCount[l-1]);
            ll x = (numberUpto[r] - (numBefore*pow10[k] % M)+M) %M;
            res[i] = (int)((x*sum)%M);
        }
        return res;
    }
};