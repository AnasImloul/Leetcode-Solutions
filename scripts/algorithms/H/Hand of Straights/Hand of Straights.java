// Runtime: 96 ms (Top 31.30%) | Memory: 61.2 MB (Top 7.04%)
class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if(hand.length % groupSize != 0)
            return false;

        Map<Integer, Integer> map = new HashMap<>();
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for(int card : hand){
            if(map.containsKey(card))
                map.put(card, map.get(card) + 1);
            else {
                map.put(card, 1);
                minHeap.add(card);
            }
        }

        while(!minHeap.isEmpty()){
            int min = minHeap.peek();
            for(int i=min; i < min + groupSize; i++){
                if(!map.containsKey(i) || map.get(i) == 0)
                    return false;
                map.put(i, map.get(i) - 1);
                if(map.get(i) == 0){
                    if(minHeap.peek() != i)
                        return false;
                    minHeap.poll();
                }
            }
        }
        return true;
    }
}