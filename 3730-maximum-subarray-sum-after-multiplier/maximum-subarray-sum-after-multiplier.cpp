class Solution {
    #define ll long long

    ll transform(const int& ele,const int& k,const bool is_positive){
        if(is_positive)
            return 1LL*ele*k;
        return ele>=0? floor(ele/k) : ceil(ele/k);
    }

    ll maxSumSubarray(vector<int>& nums,const int& k,const bool is_positive){
        int n = nums.size();
        vector<ll> no_trans(n),curr_trans(n),ended_trans(n);
    
        no_trans[0] = nums[0];
        curr_trans[0] = transform(nums[0],k,is_positive);
        ended_trans[0] = LLONG_MIN/8; 
        for(int i=1;i<n;++i){
            ll transformed_curr = transform(nums[i],k,is_positive);

            no_trans[i] = max<ll>(no_trans[i-1]+nums[i],nums[i]);
            curr_trans[i] = max<ll>({no_trans[i-1]+transformed_curr,curr_trans[i-1]+transformed_curr,transformed_curr});
            ended_trans[i] = max<ll>({curr_trans[i-1]+nums[i],ended_trans[i-1]+nums[i]});
        }

        ll max_sum = LLONG_MIN/8;
        for(int i=0;i<n;++i)
            max_sum = max<ll>({max_sum,curr_trans[i],ended_trans[i]});
        
        return max_sum;
    }
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(maxSumSubarray(nums,k,true),maxSumSubarray(nums,k,false));
    }
};