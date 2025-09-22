class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101];
        for(int i = 0;i<101;i++){
            freq[i]=0;
        }
        int maxFreq = 0;
        for(int i=0 ; i<nums.size();i++){
            freq[nums[i]]++;
            maxFreq = max(maxFreq,freq[nums[i]]);
        }
        int result = 0;
        for(int i = 0 ;i< 101 ;i++){
            if(freq[i]==maxFreq) result+=maxFreq;
        }
        return result;
    }
};