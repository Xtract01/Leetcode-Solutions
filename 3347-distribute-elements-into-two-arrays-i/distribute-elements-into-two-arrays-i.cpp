class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a,b;
        vector<int> res;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        for(int i=2 ; i<n ; i++){
            if(a.back()>b.back()) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        for(int i=0 ; i<a.size() ; i++){
            res.push_back(a[i]);
        }
        for(int i=0 ; i<b.size();i++){
            res.push_back(b[i]);
        }
        return res;
    }
};