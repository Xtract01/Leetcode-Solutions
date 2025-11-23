class Solution {
public:
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> remainOne;
        vector<int> remainTwo;
        for(int &num : nums){
            sum+= num;
            if(num % 3==1) remainOne.push_back(num);
            else if(num % 3 ==2) remainTwo.push_back(num);
        }
        if(sum % 3 ==0 ) return sum;
        sort(begin(remainOne),end(remainOne));
        sort(begin(remainTwo),end(remainTwo));
        int result = 0;
        int remainder = sum % 3;
        if(remainder == 1){
            int remove1 = remainOne.size()>=1 ? remainOne[0] : INT_MAX;
            int remove2 = remainTwo.size()>=2 ?remainTwo[0] + remainTwo[1] :INT_MAX;
            result = max(result,sum-min(remove1,remove2));
        }
        else {
            int remove1 = remainTwo.size()>=1 ? remainTwo[0] : INT_MAX;
            int remove2 = remainOne.size()>=2 ?remainOne[0] + remainOne[1] :INT_MAX;
            result = max(result,sum-min(remove1,remove2));
        }
        return result;
    }
};