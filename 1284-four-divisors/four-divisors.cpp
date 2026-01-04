class Solution {
public:
    int solve(int num){
        int sum = 0;
        int count = 0;
        for(int factor=1; factor*factor<=num ; factor++ ){
            if(num % factor == 0 ){
                int otherFactor = num / factor;
                if(factor==otherFactor){
                    count+=1;
                    sum+=factor;
                }
                else {
                    count+=2;
                    sum = sum + factor + otherFactor;
                }
            }
            if(count >4){
                return 0;
            }
        }
        if(count==4) return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for(int &num : nums){
            result+=solve(num);
        }
        return result;
    }
};