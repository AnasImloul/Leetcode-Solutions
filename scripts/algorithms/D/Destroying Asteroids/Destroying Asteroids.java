// Runtime: 476 ms (Top 5.23%) | Memory: 135.2 MB (Top 5.23%)
class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a,b)->b-a);
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for(int val:asteroids)
            maxHeap.add(val);

        long bigMass = mass;

        while(maxHeap.size()>0){
            int curr = maxHeap.poll();

            if(bigMass>=curr){
                bigMass+=curr;
                while(minHeap.size()>0 && bigMass>=minHeap.peek()){
                    bigMass+=minHeap.poll();
                }
            }
            else{
                minHeap.add(curr);
            }
        }

        return minHeap.size()==0 && maxHeap.size()==0;
    }
}