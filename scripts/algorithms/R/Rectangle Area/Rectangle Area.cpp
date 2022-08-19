// Runtime: 17 ms (Top 23.83%) | Memory: 5.9 MB (Top 77.72%)

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rec1=abs(ax2-ax1)*abs(ay2-ay1); //Area(Rectangle 1)
        int rec2=abs(bx2-bx1)*abs(by2-by1); //Area(Rectangle 2)

        //As explained above, if intervals overlap, max(x1,x3) < min(x2,x4) and overlapped interval
        //is ( max(x1,x3) , min(x2,x4) ).

        int ox1=(max(ax1,bx1)-min(ax2,bx2)); //if ox1 is negative, abs(ox1) is the length of overlapped rectangle, else rectangles do not overlap.
        int oy1=(max(ay1,by1)-min(ay2,by2)); //breadth of overlapped rectangle

        int rec3=0; //if rectangles do not overlap, area of overlapped rectangle is zero.
        if(ox1<0&&oy1<0) //if both ox1 and oy2 are negative, two rectangles overlap.
            rec3=ox1*oy1;
        return rec1+rec2-rec3; //Area(Rectangle 1) + Area(Rectangle 2) - Area(Overlapped triangle)
    }
};