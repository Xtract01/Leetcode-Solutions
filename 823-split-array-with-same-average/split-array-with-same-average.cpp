class Solution {
public:
    bool binarySearch(vector<int> &arr, int rightSubSum){
        int low = 0;
        int high = arr.size() - 1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] == rightSubSum) return true;
            else if(arr[mid]<rightSubSum) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int N = nums.size();
        int S = accumulate(begin(nums),end(nums),0);

        int n1 = N/2;
        int n2 = N - n1;

        unordered_map<int,vector<int>> sumsLeft;
        for(int mask = 0 ; mask < (1<<n1) ; mask++){
            int s = 0 ;
            int count = 0;
            for(int i=0 ; i<n1 ; i++){
                if(mask & (1<<i)){
                    s+=nums[i];
                    count++;
                }
            }
            sumsLeft[count].push_back(s);
        }
        unordered_map<int,vector<int>> sumsRight;
        for(int mask = 0 ; mask < (1<<n2) ; mask++){
            int s = 0 ;
            int count = 0;
            for(int i=0 ; i<n2 ; i++){
                if(mask & (1<<i)){
                    s+=nums[i+n1];
                    count++;
                }
            }
            sumsRight[count].push_back(s);
        }
        for(int count = 0 ; count<=n2 ; count++){
            sort(begin(sumsRight[count]),end(sumsRight[count]));
        }
        for(int k=0 ; k<=n1 ; k++){
            for(int leftSubSum : sumsLeft[k]){
                for(int m = 0 ; m<=n2 ; m++){
                    int size = k+m;
                    if(size==0 || size==N) continue;
                    if(size*S % N !=0) continue;
                    int rightSubSum = size*S/N - leftSubSum;
                    if(binarySearch(sumsRight[m],rightSubSum)) return true;
                }
            }
        }
        return false;
    }
};