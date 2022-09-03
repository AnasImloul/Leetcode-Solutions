// Runtime: 9 ms (Top 31.54%) | Memory: 43.4 MB (Top 14.91%)
class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for(int val : nums) minHeap.add(val);

        while(k > 0){

            int curr = minHeap.poll();
            minHeap.add(-curr);
            k--;
        }

        int sum = 0;
        while(!minHeap.isEmpty()){
            sum += minHeap.poll();
        }
        return sum;
    }
}