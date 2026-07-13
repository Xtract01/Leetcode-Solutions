class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i=1 ; i<9 ; i++) q.push(i);
        vector<int> res;
        while(!q.empty()){
            int el = q.front(); 
            q.pop();
            if(el>=low && el<=high) res.push_back(el);
            if(el>high) break;
            int l = el%10;
            if(l!=9) q.push(el*10+(l+1));
        }
        return res;
    }
};