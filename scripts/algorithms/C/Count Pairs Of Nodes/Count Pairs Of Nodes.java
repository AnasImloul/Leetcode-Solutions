class Solution {
    public int[] countPairs(int n, int[][] edges, int[] queries) {
        Map<Integer, Map<Integer, Integer>> dupMap = new HashMap<>();
        Map<Integer, Set<Integer>> map = new HashMap<>();
        int[] ans = new int[queries.length];
        int[] count = new int[n];
        for (int[] e : edges){
            int min = Math.min(e[0]-1, e[1]-1);
            int max = Math.max(e[0]-1, e[1]-1);
            dupMap.computeIfAbsent(min, o -> new HashMap<>()).merge(max, 1, Integer::sum);
            map.computeIfAbsent(min, o -> new HashSet<>()).add(max);
            count[min]++;
            count[max]++;
        }
        Integer[] indexes = IntStream.range(0, n).boxed().toArray(Integer[]::new);
        Arrays.sort(indexes, Comparator.comparingInt(o -> count[o]));
        for (int j = 0, hi = n; j < queries.length; j++, hi = n){
            for (int i = 0; i < n; i++){
                while(hi>i+1&&count[indexes[i]]+count[indexes[hi-1]]>queries[j]){
                    hi--;
                }
                if (hi==i){
                    hi++;
                }
                ans[j]+=n-hi;
                for (int adj : map.getOrDefault(indexes[i], Set.of())){
                    int ttl = count[indexes[i]] + count[adj];
                    if (ttl > queries[j] && ttl-dupMap.get(indexes[i]).get(adj) <= queries[j]){
                        ans[j]--;
                    }
                }
            }
        }
        return ans;
    }
}
