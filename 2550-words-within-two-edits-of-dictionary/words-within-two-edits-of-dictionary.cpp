class Solution {
public:
   int diffCount(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 2) return diff;
    }
    return diff;
}
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n = queries.size();
        int m  = dictionary.size();
        for(int i=0 ; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(diffCount(queries[i],dictionary[j])<=2){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};