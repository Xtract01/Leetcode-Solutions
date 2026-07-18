class Solution {
public:
    int gcd(int a, int b){
        if(a==0 || b==0) return 0;
        while(b!=0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        return gcd(maxi,mini);
    }
};