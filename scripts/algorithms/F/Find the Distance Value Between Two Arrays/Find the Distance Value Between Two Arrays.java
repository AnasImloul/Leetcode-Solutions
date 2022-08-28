// Runtime: 5 ms (Top 68.55%) | Memory: 44.9 MB (Top 25.67%)
class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int x=0,val=0;
        for(int i:arr1){
            for(int j:arr2){
                if(Math.abs(i-j)<=d){
                   x--;
                    break;
                }
            }
            x++;
        }
      return x;
    }
}