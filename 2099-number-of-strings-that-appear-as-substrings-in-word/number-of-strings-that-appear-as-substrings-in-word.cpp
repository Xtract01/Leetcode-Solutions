class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        set<string>st;
        int res =0;
        for (int i = 0; i < word.size(); i++) {
            string curr = "";
            for (int j = i; j < word.size(); j++) {
                curr += word[j];
                st.insert(curr);
            }
        }
        for(int i=0 ; i<patterns.size();i++){
            string find = patterns[i];
            if(st.count(find)!=0) res++;
        }
        return res;
    }
};