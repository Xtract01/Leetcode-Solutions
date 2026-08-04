class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());

        int cnt = nums[0];

        for (int x : nums) {
            while (cnt < x) {
                res.push_back(cnt);
                cnt++;
            }
            if (cnt == x)
                cnt++;
        }

        return res;
    }
};