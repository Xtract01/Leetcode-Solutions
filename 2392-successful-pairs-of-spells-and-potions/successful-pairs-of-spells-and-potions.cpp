class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();
        sort(begin(potions),end(potions));
        vector<int> answer;
        for(int i =0 ; i< m ; i++){
            int spell = spells[i];
            long long minPotion = ceil((1.0*success)/spell);
            int maxPotionVal = potions[n-1];
            if(minPotion > maxPotionVal){
                answer.push_back(0);
                continue;
            }
            int index = lower_bound(begin(potions),end(potions),minPotion) - begin(potions);
            int count = n-index;
            answer.push_back(count);
        }
        return answer;
    }
};