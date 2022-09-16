// Runtime: 72 ms (Top 44.52%) | Memory: 128.2 MB (Top 22.61%)
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<int []> pq = new PriorityQueue<>(
            (a, b) -> (a[0] + a[1]) - (b[0] + b[1])
        );
        for(int i = 0; i < nums1.length && i < k; i++){
            pq.add(new int[]{nums1[i], nums2[0], 0});
        }

        List<List<Integer>> res = new ArrayList<>();
        for(int i = 0; i < k && !pq.isEmpty(); i++){
            int [] curr = pq.poll();
            res.add(Arrays.asList(curr[0], curr[1]));
            int idx2 = curr[2];
            if(idx2 < nums2.length - 1){
                pq.add(new int[]{curr[0], nums2[idx2 + 1], idx2 + 1});
            }
        }
        return res;
    }
}