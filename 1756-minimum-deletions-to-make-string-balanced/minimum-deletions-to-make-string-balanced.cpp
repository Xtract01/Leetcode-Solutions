class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        stack<char> st;
        int i = 0;
        int ans = 0;
        while(i<n){
            if(s[i]=='a' && !st.empty() && st.top()=='b'){
                st.pop();
                ans++;
            }
            else st.push(s[i]);
            i++;
        }
        return ans;
    }
};