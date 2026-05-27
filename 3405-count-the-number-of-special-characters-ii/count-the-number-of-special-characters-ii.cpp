class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                lastLower[word[i] - 'a'] = i;
            }
            if (word[i] >= 'A' && word[i] <= 'Z') {
                int idx = word[i] - 'A';
                if (firstUpper[idx] == -1) {
                    firstUpper[idx] = i;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {
                ans++;
            }
        }
        return ans;
    }
};