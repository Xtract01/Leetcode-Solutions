class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xDist = abs(z-x);
        int yDist = abs(z-y);
        if(xDist==yDist) return 0;
        else if(xDist<yDist) return 1;
        else return 2;
    }
};