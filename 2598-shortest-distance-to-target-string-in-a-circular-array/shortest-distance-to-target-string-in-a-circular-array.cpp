class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        if(words[startIndex]==target) return 0;
        int ans =   INT_MAX;
        int cnt = 0;
        int i = startIndex;
        while(cnt<n){
            if(words[(startIndex + cnt)%n]==target) ans = min(ans,cnt);
            cnt++;
        }
        cnt = 0;
        while(cnt<n){
            if(words[(startIndex - cnt + n)%n]==target) ans = min(ans,cnt);
            cnt++;
        }
        return ans==INT_MAX ? -1 : ans;

    }
};