class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int min=Integer.MAX_VALUE, index=-1, i;
        
        for ( i=0;i<points.length;i++){
            if (x==points[i][0] ||  y==points[i][1]){
                 int d = Math.abs(x - points[i][0]) + Math.abs(y - points[i][1]);
                if (d<min){
                    min=d;
                    index=i;
                }
            }
            
        }
        // if ( min== Integer.MAX_VALUE) return -1; --> no longer needed as index is initialized as -1 in the declartion.
        return  index;
        
    }
}
