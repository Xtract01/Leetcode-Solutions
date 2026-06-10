class SegmentTree {
    vector<int> segmentTree;
    bool isMinTree;

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);

        if (isMinTree)
            segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        else
            segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    int querySegmentTree(int start, int end, int i, int l, int r) {
        if (l > end || r < start)
            return isMinTree ? INT_MAX : INT_MIN;

        if (l >= start && r <= end)
            return segmentTree[i];

        int mid = l + (r - l) / 2;

        int a = querySegmentTree(start, end, 2 * i + 1, l, mid);
        int b = querySegmentTree(start, end, 2 * i + 2, mid + 1, r);

        return isMinTree ? min(a, b) : max(a, b);
    }

public:
    SegmentTree(vector<int>& nums, bool flag) {
        int n = nums.size();

        isMinTree = flag;
        segmentTree.resize(4 * n);

        buildSegmentTree(0, 0, n - 1, nums);
    }

    int query(int l, int r, int n) {
        return querySegmentTree(l, r, 0, 0, n - 1);
    }
};

class Solution {
public:
    using ll = long long;

    ll getValue(int l, int r,
                SegmentTree& minST,
                SegmentTree& maxST,
                int n) {
        int minEl = minST.query(l, r, n);
        int maxEl = maxST.query(l, r, n);

        return (ll)maxEl - minEl;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree minST(nums, true);
        SegmentTree maxST(nums, false);

        priority_queue<tuple<ll, int, int>> pq;

        for (int l = 0; l < n; l++) {
            ll value = getValue(l, n - 1, minST, maxST, n);
            pq.push({value, l, n - 1});
        }

        ll result = 0;

        while (k-- && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();

            result += val;

            if (l < r) {
                ll nextBestValue =
                    getValue(l, r - 1, minST, maxST, n);

                pq.push({nextBestValue, l, r - 1});
            }
        }

        return result;
    }
};