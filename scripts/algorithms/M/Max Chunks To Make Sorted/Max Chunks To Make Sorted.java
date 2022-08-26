// Runtime: 0 ms (Top 100.00%) | Memory: 40.9 MB (Top 81.61%)
class Solution {
    public int maxChunksToSorted(int[] arr) {

        int max=0, count=0;
        for(int i=0; i<arr.length; i++){
            max = Math.max(arr[i],max);
            if(i==max) count++;
        }return count;
    }
}