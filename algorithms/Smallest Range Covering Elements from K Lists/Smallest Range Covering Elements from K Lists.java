class Solution {
    
    class Pair implements Comparable<Pair> {
        int val;
        int li;
        int di;
        
        public Pair(int val, int li, int di) {
            this.val = val;
            this.li = li;
            this.di = di;
        }
        
        public int compareTo(Pair other) {
            return this.val - other.val;
        }
    }
    
    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        int max = Integer.MIN_VALUE;
        for(int i=0; i<nums.size(); i++) {
            pq.add(new Pair(nums.get(i).get(0), i, 0));
            max = Math.max(max, nums.get(i).get(0));
        }
        
        int rbeg = 0;
        int rend = 0;
        int rsize = Integer.MAX_VALUE;
        
        while(pq.size() == nums.size()) {
            Pair rem = pq.remove();
            int crsize = max - rem.val;
            
            if(crsize < rsize) {
                rsize = crsize;
                rbeg = rem.val;
                rend = max;
            }
            
            if(rem.di < nums.get(rem.li).size() - 1) {
                pq.add(new Pair(nums.get(rem.li).get(rem.di + 1), rem.li, rem.di + 1));
                max = Math.max(max, nums.get(rem.li).get(rem.di + 1));
            }
        }
        
        return new int[]{rbeg, rend};
    }
}
