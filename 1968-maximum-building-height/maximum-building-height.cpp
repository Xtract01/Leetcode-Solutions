class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        int m = restrictions.size();

        vector<vector<int>> arr(m + 2, vector<int>(2));

        for (int i = 0; i < m; i++) {
            arr[i] = restrictions[i];
        }

        arr[m] = {1, 0};
        arr[m + 1] = {n, n - 1};

        sort(arr.begin(), arr.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        int len = arr.size();

        // Left -> Right
        for (int i = 1; i < len; i++) {
            arr[i][1] = min(
                arr[i][1],
                arr[i - 1][1] + (arr[i][0] - arr[i - 1][0])
            );
        }

        // Right -> Left
        for (int i = len - 2; i >= 0; i--) {
            arr[i][1] = min(
                arr[i][1],
                arr[i + 1][1] + (arr[i + 1][0] - arr[i][0])
            );
        }

        int ans = 0;

        for (int i = 1; i < len; i++) {

            int leftPos = arr[i - 1][0];
            int leftH   = arr[i - 1][1];
            int rightPos = arr[i][0];
            int rightH   = arr[i][1];
            int dist = rightPos - leftPos;
            int peak = leftH + (dist + rightH - leftH) / 2;

            ans = max(ans, peak);
        }

        return ans;
    }
};