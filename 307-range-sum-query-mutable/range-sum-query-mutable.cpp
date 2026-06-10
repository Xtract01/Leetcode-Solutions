class NumArray {
public:
    int n ;
    vector<int> segmentTree;
    int Query(int start , int end , int i, int l , int r){
        if(l>end || r<start) return 0;
        if(l>=start && r<=end) return segmentTree[i];
        int mid = l+(r-l)/2;
        return Query(start,end,2*i+1,l,mid)+Query(start,end,2*i+2,mid+1,r);

    }
    void updateSegmentTree(int index, int val , int i , int l, int r){
        if(l==r){
            segmentTree[i] = val;
            return;
        }
        int mid = l+(r-l)/2;
        if(index<=mid){
            updateSegmentTree(index,val,2*i+1,l,mid);
        }
        else {
            updateSegmentTree(index,val,2*i+2,mid+1,r);
        }
        segmentTree[i] = segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    void buildSegTree(int i, int l , int r, vector<int> &nums){
        if(l==r){
            segmentTree[i] = nums[r];
            return;
        }
        int mid = l+(r-l)/2;
        buildSegTree(2*i+1,l,mid,nums);
        buildSegTree(2*i+2,mid+1,r,nums);
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildSegTree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        updateSegmentTree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return Query(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */