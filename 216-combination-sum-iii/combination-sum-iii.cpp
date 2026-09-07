class Solution {
public:
    void solve(int ind , int k , int n , vector<vector<int>> &ans,vector<int> &temp){
        if(temp.size() == k && n==0){
            ans.push_back(temp);
            return;
        }
        if(n<0 || temp.size() >k){
            return;
        }
        for(int i = ind; i <= 9; i++){
            temp.push_back(i);
            solve(i + 1, k, n - i, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,k,n,ans,temp);
        return ans;
    }
};