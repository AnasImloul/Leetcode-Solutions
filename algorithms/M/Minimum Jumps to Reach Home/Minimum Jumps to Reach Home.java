class Solution {
    public int minimumJumps(int[] forbidden, int a, int b, int x) {
        
        // Visited Set
        Set<Integer> visited = new HashSet<Integer>();
        
        // Add forbidden coordinates to visited
        for (int i = 0; i < forbidden.length; i++) {
            visited.add(forbidden[i]);
        }
        
        // Distance/ Jumps map
        Map<Integer, Integer> jumps = new HashMap<>();
        jumps.put(0, 0);
        
        // BFS Queue
        Queue<Integer[]> q = new LinkedList<>();
        q.add(new Integer[] {0, 1});
        
        // BFS 
        while (q.size() != 0) {
            
            Integer[] ud = q.poll();
            
            int u = ud[0], d = ud[1];
            
            // x found
            if (u == x) {
                return jumps.get(u);
            }
            
            // jump right
            if (u + a < 6001 && !visited.contains(u+a)) {
                q.add(new Integer[] {u+a, 1});
                visited.add(u+a);
                jumps.put(u+a, jumps.get(u) + 1);
            }
            
            // jump left
            if (d != -1 && u - b > -1 && !visited.contains(u-b)) {
                q.add(new Integer[] {u-b, -1});
                jumps.put(u-b, jumps.get(u) + 1);
            }
            
        }
        
        return -1;
        
    }
}
