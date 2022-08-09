class Solution {
    public int kthSmallest(int[][] mat, int k) {
        int[] row = mat[0];
        
        for(int i=1; i<mat.length; i++) {
            row = findKthSmallest(row, mat[i], k);
        }
        
        return row[k-1];
    }
    
    private int[] findKthSmallest(int[] num1, int[] num2, int k) {
        List<Integer> list = new ArrayList<>();
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a,b) -> (a[0]+a[1]) - (b[0]+b[1]));
        
        for(int i=0; i<num1.length && i<k; i++) {
            minHeap.offer(new int[]{num1[i], num2[0], 0});
        }
        
        for(int i=0; i<k && !minHeap.isEmpty(); i++) {
            int[] candidate = minHeap.poll();
            list.add(candidate[0] + candidate[1]); // SUM;
            int num2Idx = candidate[2];
            
            if(num2Idx<num2.length-1) {
                minHeap.offer(new int[]{candidate[0], num2[num2Idx+1], num2Idx+1});
            }
        }
        
        return list.stream().mapToInt(i->i).toArray();
    }
}
