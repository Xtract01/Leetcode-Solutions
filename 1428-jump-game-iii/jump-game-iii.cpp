class Solution {
public:
    bool solve(int i , vector<int> &arr,vector<int>& vis){
        if(arr[i]==0) return true;
           vis[i] = 1;
        bool ch1=false , ch2=false;
        if(i+arr[i]<arr.size()&& !vis[i+arr[i]]) ch1 = solve(i+arr[i],arr,vis);
        if(i-arr[i]>=0 && !vis[i-arr[i]]) ch2 = solve(i-arr[i],arr,vis);
        return ch1||ch2;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if(arr[start]==0) return true;
        vector<int> vis(arr.size(), 0);
        return solve(start,arr,vis);
    }
};