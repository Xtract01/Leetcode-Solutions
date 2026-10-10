class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int maxD = 0;

        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxD = max(maxD, diff[i]);
        }

        vector<int> countDiff(maxD + 1, 0);
        for (int d : diff) {
            countDiff[d]++;
        }

        long long K = (long long)k1 + k2;

        for (int currDiff = maxD; currDiff > 0 && K > 0; currDiff--) {
            long long countOps = min<long long>(countDiff[currDiff], K);
            countDiff[currDiff] -= (int)countOps;
            countDiff[currDiff - 1] += (int)countOps;
            K -= countOps;
        }

        long long result = 0;
        for (int d = 1; d <= maxD; d++) {
            result += 1LL * countDiff[d] * d * d;
        }

        return result;
    }
};