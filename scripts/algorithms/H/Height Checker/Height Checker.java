// Runtime: 3 ms (Top 33.59%) | Memory: 42.3 MB (Top 26.32%)
class Solution {
    public int heightChecker(int[] heights) {

      int[] dupheights = Arrays.copyOfRange(heights , 0 ,heights.length);

      Arrays.sort(dupheights);
      int count = 0;

      for(int i=0 ; i< heights.length ; i++){

        if(heights[i] != dupheights[i]){
          count++;
        }

      }

      return count;

    }
}
