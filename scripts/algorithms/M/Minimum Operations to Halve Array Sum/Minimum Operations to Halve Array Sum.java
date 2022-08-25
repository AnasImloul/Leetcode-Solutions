// Runtime: 392 ms (Top 56.62%) | Memory: 107.3 MB (Top 79.45%)
class Solution {
    public int halveArray(int[] nums) {
        PriorityQueue<Double> q = new PriorityQueue<>(Collections.reverseOrder());
        double sum=0;
        for(int i:nums){
            sum+=(double)i;
            q.add((double)i);
        }
        int res=0;
        double req = sum;
        while(sum > req/2){
            double curr = q.poll();
            q.add(curr/2);
            res++;
            sum -= curr/2;
        }
        return res;
    }
}