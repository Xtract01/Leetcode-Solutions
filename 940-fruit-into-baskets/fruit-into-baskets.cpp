class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0 , r = 0, len = 0 , maxLen = 0;
        unordered_map<int,int> mp;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            else {
                len = r-l+1;
                maxLen = max(len,maxLen);
            }
            r++;
        }
        return maxLen;
    }
};