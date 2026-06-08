class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        int countLess = 0;
        int equal = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i]<pivot) countLess++;
            else if(nums[i]==pivot) equal++;
        }
        int i = 0;
        int j = countLess;
        int k = countLess+equal;
        for(int l=0 ; l<n ; l++){
            if(nums[l]<pivot){
                result[i] = nums[l];
                i++;
            }
            else if(nums[l]==pivot){
                result[j] = pivot;
                j++;
            }
            else {
                result[k] = nums[l];
                k++;
            }
        }
        return result;
    }
};