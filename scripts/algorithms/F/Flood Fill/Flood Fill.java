// Runtime: 1 ms (Top 91.13%) | Memory: 48.4 MB (Top 21.53%)
class Solution {
    void colorFill(int[][]image,int sr,int sc,int sourceColor,int targetColor){
        int m = image.length, n = image[0].length;

        if(sr>=0 && sr<m && sc>=0 && sc<n)
        {
            if( (image[sr][sc] != sourceColor) ||(image[sr][sc] == targetColor)) return;

        image[sr][sc] = targetColor;
        colorFill(image,sr,sc-1,sourceColor,targetColor); // left
        colorFill(image,sr,sc+1,sourceColor,targetColor); // right
        colorFill(image,sr-1,sc,sourceColor,targetColor); // up
        colorFill(image,sr+1,sc,sourceColor,targetColor); // down
        }
       else
           return;
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int rows = image.length, cols = image[0].length;

        colorFill(image,sr,sc,image[sr][sc],color);
    return image;
    }
}