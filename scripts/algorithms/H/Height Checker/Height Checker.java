// Runtime: 2 ms (Top 76.12%) | Memory: 42 MB (Top 50.36%)
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
