class Solution {
public:
    bool hasDuplicate(string s1 ,string s2){
        vector<int> hash(26,0);
        for(char ch : s1) {
            int idx = ch - 'a';
            if(hash[idx]) return true;
            hash[idx]++;
        }
        for(char ch : s2) {
            int idx = ch - 'a';
            if(hash[idx]) return true;
            hash[idx]++;
        }

        return false;
    }
    int solve(int i, vector<string> &arr, string temp,int n){
        if(i>=n) return temp.length();
        int include = 0 , exclude = 0;
        if(hasDuplicate(temp,arr[i])) exclude = solve(i+1,arr,temp,n);
        else {
            exclude = solve(i+1,arr,temp,n);
            include = solve(i+1,arr,temp+arr[i],n);
        }
        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();
        return solve(0,arr,temp,n);
    }
};