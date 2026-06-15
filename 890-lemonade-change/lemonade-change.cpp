class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        unordered_map<int,int> mp;
        for(int i=0 ; i<n; i++){
            mp[bills[i]]++;
            if(bills[i]==10){
                if(mp[5]==0) return false;
                else mp[5]--;
            }
            if(bills[i]==20){
                if(mp[10]>=1 && mp[5]>=1 ){
                    mp[10]-=1;
                    mp[5]-=1;
                }
                else if(mp[5]>=3){
                    mp[5]-=3;
                }
                else return false;
            }
        }
        return true;

    }
};