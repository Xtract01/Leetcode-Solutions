class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0 , count =0;
        unordered_map<int,int> mp;
        for(int i=0 ; i<n ; i++){
            sum+=arr[i];
            if(sum==k) count++;
            int diff = sum - k;
            if(mp.find(diff)!=mp.end()) count+=mp[diff];
            mp[sum]++;
        }
        return count;
    }
};