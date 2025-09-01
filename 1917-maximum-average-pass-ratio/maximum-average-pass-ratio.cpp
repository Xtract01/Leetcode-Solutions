class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> maxHeap;
        auto gain = [](int x, int y) -> double {
            return (double)(x + 1) / (y + 1) - (double)x / y;
        };
        for(auto el : classes){
            int x = el[0];
            int y = el[1];
            maxHeap.push({gain(x,y),{x,y}});
        }
        while(extraStudents>0){
            pair<double,pair<int,int>> el = maxHeap.top();
            int x = el.second.first;
            int y = el.second.second;
            maxHeap.pop();
            x=x+1;
            y=y+1;
            maxHeap.push({gain(x,y),{x,y}});
            extraStudents--;

        }
        double ans = 0;
        while(!maxHeap.empty()){
            ans += (double)maxHeap.top().second.first/ maxHeap.top().second.second;
            maxHeap.pop();
        }
        return ans/classes.size();

    }
};