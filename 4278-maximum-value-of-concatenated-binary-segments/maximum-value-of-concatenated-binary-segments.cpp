class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
    int nmx = 3 * 1e5;
    vector<ll> pow2(nmx); pow2[0] = 1;
    for(int i = 1; i < nmx; i++) {
        pow2[i] = (pow2[i-1]*2) % mod;
    }

    int n = nums1.size();
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = i;

    sort(v.begin(), v.end(), [&](int i, int j) {
        if(nums1[i] == nums1[j]) return nums0[i] > nums0[j];
        if(!nums0[i]) return false;
        if(!nums0[j]) return true;
        return nums1[i] < nums1[j];
    });

    ll ans = 0, pw = 0;
    for(auto i : v) {
        pw += nums0[i];
        while(nums1[i]--) {
            ans = (ans + pow2[pw]) % mod;
            pw++;
        }
    }
    return ans;
}
};