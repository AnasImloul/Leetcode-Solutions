// Runtime: 785 ms (Top 5.01%) | Memory: 176.5 MB (Top 5.07%)
class Solution {
    public long countExcellentPairs(int[] nums, int k) {
        HashMap<Integer,Set<Integer>> map = new HashMap<>();
        for(int i : nums){
            int x = Integer.bitCount(i);
            map.putIfAbsent(x,new HashSet<>());
            map.get(x).add(i);
        }
        long ans = 0;
        HashSet<Integer> vis = new HashSet<>();
        for(int i : nums){
            if(vis.contains(i)) continue;
            int need = Math.max(0,k-Integer.bitCount(i));
            for(int key : map.keySet()) // runs at max 30 times
                if(key >= need) ans += (long) map.get(key).size();
            vis.add(i);
        }
        return ans;
    }
}