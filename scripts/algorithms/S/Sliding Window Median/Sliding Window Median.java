// Runtime: 176 ms (Top 24.15%) | Memory: 56.2 MB (Top 31.72%)
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        Queue<Integer> minHeap = new PriorityQueue<>();
        Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        double[] res = new double[nums.length - k + 1];
        for(int i = 0; i< nums.length; i++){
            if(i >= k){
                if(!minHeap.remove(nums[i-k]))
                    maxHeap.remove(nums[i-k]);
            }

            // If k is odd, max heap is of odd size and min heap is of even
            // else both are of even size
            if(!maxHeap.isEmpty() && nums[i] <= maxHeap.peek()) {
                maxHeap.add(nums[i]);
                if(((k&1) == 1 && maxHeap.size() > k/2+1) || ((k&1) == 0 && maxHeap.size() > k/2)){
                    minHeap.offer(maxHeap.poll());
                }
            }else{
                minHeap.add(nums[i]);
                if(minHeap.size() > k/2){
                    maxHeap.offer(minHeap.poll());
                }
            }
            while(!minHeap.isEmpty() && !maxHeap.isEmpty() && maxHeap.peek() > minHeap.peek()){
                int temp1 = maxHeap.poll();
                int temp2 = minHeap.poll();
                maxHeap.add(temp2);
                minHeap.add(temp1);
            }
            if(minHeap.size() + maxHeap.size() == k){
                if((k&1)==1){
                    res[i-k+1] = maxHeap.peek();
                }else{
                    res[i-k+1] = ((long)minHeap.peek()+ (long)maxHeap.peek())/2.0;
                }
            }
        }
        return res;
    }
}