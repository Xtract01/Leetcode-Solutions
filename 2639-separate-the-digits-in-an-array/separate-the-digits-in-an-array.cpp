class Solution {
public:
    vector<int> sepNum(int num){
        vector<int> res;
        while(num>0){
            int l = num%10;
            res.push_back(l);
            num/=10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int &num : nums){
            vector<int> sep = sepNum(num);
            for(int &e : sep) ans.push_back(e);
        }
        return ans;
    }
};