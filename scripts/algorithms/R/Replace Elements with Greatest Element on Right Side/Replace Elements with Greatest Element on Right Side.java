// Runtime: 2 ms (Top 67.33%) | Memory: 55.1 MB (Top 5.58%)
class Solution {
    public int[] replaceElements(int[] arr) {
      int greatElement = -1;
        for(int i = arr.length-1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = greatElement;
            greatElement = Math.max(temp, greatElement);
        }
        return arr;
    }
}