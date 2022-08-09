class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
      Arrays.sort(arr);
      arr[0] = 1;
      for(int i = 1;i<arr.length;i++){
         if(Math.abs(arr[i] - arr[i-1]) > 1)
            arr[i] = arr[i-1] + 1;    
      }
      return arr[arr.length-1];
    }
}