class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int,vector<int>> mp;
        for(int i=0 ; i<n ; i++){
            mp[nums[i]].push_back(i);
        }
        for(auto p:mp){
            vector<int> &el = p.second;
            if(el.size()>=3){
                sort(el.begin(),el.end());
                int sz = el.size();
                int i = 0 , j = 2;
                while(j<sz){
                    int curr = abs(el[i]-el[i+1]) + abs(el[i+1]-el[j]) + abs(el[j]-el[i]);
                    ans = min(ans,curr);
                    i++;
                    j++;
                }
            }
        }
        return (ans==INT_MAX) ? -1 : ans;
    }
};