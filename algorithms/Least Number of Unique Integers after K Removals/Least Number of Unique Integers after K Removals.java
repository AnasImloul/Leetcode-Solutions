class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer,Integer> freqMap = new HashMap<>();
        for(int a: arr) freqMap.put(a, freqMap.getOrDefault(a,0)+1);
        PriorityQueue<Integer> pq = new PriorityQueue<>((i1,i2)->Integer.compare(freqMap.get(i1), freqMap.get(i2)));
        pq.addAll(freqMap.keySet());
        while(k>0 && !pq.isEmpty()){
            int element = pq.poll();
            int toBeDeleted = Math.min(k,freqMap.get(element));
            k-=toBeDeleted;
            if(toBeDeleted<freqMap.get(element)) 
                pq.add(element);
        }
        return pq.size();
    }
}
