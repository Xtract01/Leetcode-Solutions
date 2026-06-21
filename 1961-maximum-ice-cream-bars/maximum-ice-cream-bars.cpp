class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int total = coins;
        int res = 0;
        for(int i=0 ; i<n ; i++){
            if(total>=costs[i]){
                total-=costs[i];
                res++;
            }
            else break;

        }
        return res;
    }
};