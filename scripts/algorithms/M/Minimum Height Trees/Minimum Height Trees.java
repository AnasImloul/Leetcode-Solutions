// Runtime: 100 ms (Top 13.14%) | Memory: 86.2 MB (Top 13.59%)
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if(edges.length == 0) {
            List<Integer> al = new ArrayList<>();
            al.add(0);
            return al;
        }
        HashMap<Integer, Set<Integer>> map = new HashMap<>(); // map == graph
        int [] degree = new int[n];
        for(int [] edge : edges){
            int src = edge[0];
            int dest = edge[1];
            map.putIfAbsent(src, new HashSet<>());
            map.get(src).add(dest);
            map.putIfAbsent(dest, new HashSet<>());
            map.get(dest).add(src);
            degree[src]++;
            degree[dest]++;
        }
        Queue<Integer> q = new ArrayDeque<>();
        for(int i = 0; i < degree.length; i++){
            if(degree[i] == 1){
                q.offer(i);
            }
        }
        int count = n;
        while(count > 2){
            int size = q.size();
            count -= size;
            while(size-- > 0){
                Integer src = q.poll();

                for(Integer connection : map.get(src)){
                    degree[connection]--;
                    if(degree[connection] == 1){
                        q.offer(connection);
                    }
                }
            }
        }
        return new ArrayList<>(q);
    }
}