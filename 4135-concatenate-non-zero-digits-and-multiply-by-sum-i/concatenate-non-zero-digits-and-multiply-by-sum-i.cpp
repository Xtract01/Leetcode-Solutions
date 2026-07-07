class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = n;
        string s = "";
        while(x>0){
            int l =  x%10;
            if(l!=0){
                s+= char('0'+l);
            }
            x/=10;
        }
        reverse (s.begin(),s.end());
        if (s.empty())
            return 0;
        long long res = stoll(s);
        int sum = 0;
        for(char c : s) sum += (c - '0');
        return res * sum;
    }
};