class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        long long max = *max_element(nums.begin(),nums.end());
        long long min = *min_element(nums.begin(),nums.end());
        return k*(max-min);
    }
};