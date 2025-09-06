class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        int i =0;
        string res ="";
        string first = strs[0];
        string last = strs[n-1];
        while(i<first.size() && i<last.size() && first[i]==last[i]){
            res+=first[i];
            i++;
        }
        return res;
    }
};