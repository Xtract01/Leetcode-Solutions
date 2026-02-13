class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i =0,j=n-1 , maxi = INT_MIN ;
        while(i<j){
            maxi=max(maxi,(j-i)*min(height[i],height[j]));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxi;
    }
};