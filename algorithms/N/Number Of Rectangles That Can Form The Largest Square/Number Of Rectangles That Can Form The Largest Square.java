class Solution {
    public int countGoodRectangles(int[][] rectangles) {
        int cnt = 0, max = 0;
        for (int []rectangle: rectangles) {
	    //	get the minimum from width and height
            int side = Math.min(rectangle[0], rectangle[1]); //[4,6], you can cut it to get a square with a side length of at most  4.
            if (side > max) {  //comparing max side with new side 
                cnt = 1; // intialise count with 1
                max = side; //update the max by new side 
            }else if (side == max) { // square with maxlength 
                cnt++; //just increase the count of square with max len
            }
        }
        return cnt;
    }
}
