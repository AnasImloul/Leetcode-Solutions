// Runtime: 28 ms (Top 89.13%) | Memory: 48.60 MB (Top 83.44%)

class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int[] res = {-100000 , 100000};
        PriorityQueue<int[]>pq = new PriorityQueue<>((a , b) -> a[0] - b[0]);
        int max = Integer.MIN_VALUE;
        int k = nums.size();

        for(int i = 0; i < k; i++){
            int minElem = nums.get(i).get(0);
            int[] arr = {minElem , 0 , i};

            max = Math.max(max , minElem);
            pq.add(arr);

        }
        while(true){
            int min[] = pq.poll();
            if(res[1] - res[0] > max - min[0]){
                res[1] = max;
                res[0] = min[0];
            }
            min[1]++;

            List<Integer>cur = nums.get(min[2]);

            if(min[1] == cur.size()){
                break;
            }
            else{
                min[0] = cur.get(min[1]);
                max = Math.max(max , cur.get(min[1]));
                pq.add(min);
            }
        }
        return res;
    }
}
