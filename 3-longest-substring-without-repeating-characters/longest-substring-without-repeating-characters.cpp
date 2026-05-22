class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j=0;
        int res = 0;
        unordered_set<char> st;
        while(j<n){
            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }
            res = max(res,j-i+1);
            st.insert(s[j]);
            j++;
        }
        return res;
    }
};