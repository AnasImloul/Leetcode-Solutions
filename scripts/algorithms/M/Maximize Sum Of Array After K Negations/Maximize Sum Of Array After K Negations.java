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
