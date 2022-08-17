class Solution {
    public int minStoneSum(int[] piles, int k) {
        Queue <Integer> heap = new PriorityQueue (new Comparator <Integer> () {
           public int compare (Integer a, Integer b) {
               if (a < b)
                   return 1;
               else if (a > b)
                   return -1;
               else
                   return 0;
           } 
        });
        for (int val : piles)
            heap.offer (val);
        while (k-- > 0) {
            int stones = heap.poll ();
            stones -= (int) (Math.floor (stones / 2));
            heap.offer (stones);
        }
        int sum = 0;
        while (!heap.isEmpty ())
            sum += heap.poll ();
        return sum;
    }
}
