class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit) {
        PriorityQueue<Pair<Integer, Integer>> maxHeap = 
            new PriorityQueue<>((a, b) -> Integer.compare(b.getKey(), a.getKey()));
        for(int i=0;i<values.length;i++) {
            maxHeap.add(new Pair<Integer, Integer>(values[i], labels[i]));
        }
        Map<Integer, Integer> labelLimitMap = new HashMap<>();
        int sum = 0;
        while(numWanted != 0) {
            int label = maxHeap.peek().getValue();
            if(labelLimitMap.containsKey(label)) {
                if(labelLimitMap.get(label) == useLimit) {
                    maxHeap.poll();
                } else {
                    labelLimitMap.put(label, labelLimitMap.get(label) + 1);
                    sum += maxHeap.poll().getKey();
                    numWanted--;
                }
            } else {
                labelLimitMap.put(label, 1);
                sum += maxHeap.poll().getKey();
                numWanted--;
            }
            // This Holds since at most numWanted is mentioned.
            if(maxHeap.isEmpty()) {
                return sum;
            }
        }
        return sum;
    }
}
