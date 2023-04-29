class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int ax1 = rec1[0];
        int ay1 = rec1[1];
        int ax2 = rec1[2];
        int ay2 = rec1[3];
 
        int bx1 = rec2[0];
        int by1 = rec2[1];
        int bx2 = rec2[2];
        int by2 = rec2[3];

        int x5 = max(ax1,bx1);
        int y5 = max(ay1,by1);
        int x6 = min(ax2,bx2);
        int y6 = min(ay2,by2);
        if(x5<x6 && y5<y6){
            return true;
        }
        else{
            return false;
        }

    }
};