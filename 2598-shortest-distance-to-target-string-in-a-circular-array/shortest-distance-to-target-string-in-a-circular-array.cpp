class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        for(int d=0 ; d<n ; d++){
            int forward = (startIndex+d)%n;
            int backward = (startIndex - d + n) % n;
            if(words[forward] == target || words[backward] == target)
                return d;
        }
        return -1;
    }
};