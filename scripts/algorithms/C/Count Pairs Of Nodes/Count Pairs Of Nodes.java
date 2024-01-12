// Runtime: 56 ms (Top 80.0%) | Memory: 92.30 MB (Top 62.86%)

class Solution {
    // Time  :  O(E + N + Q)
    // Space :  O(N + E)
    public int[] countPairs(int n, int[][] edges, int[] queries) {
        // Key: edge ID   Value: count of duplicate edge
        Map<Integer, Integer> edgeCount = new HashMap<>();
        // degree[i] : number of edge for node i (0-indexed)
        int[] degree = new int[n];
        
        for (int[] e : edges) {    // recording all edges  ==>  O(E) Time / Space
            int u = e[0] - 1;
            int v = e[1] - 1;
            degree[u]++;
            degree[v]++;
            
            int eId = Math.min(u, v) * n + Math.max(u, v);
            edgeCount.put(eId, edgeCount.getOrDefault(eId, 0) + 1);
        }
        
        // Key: Degree   Value: Frequency (number of nodes with that degree)
        Map<Integer, Integer> degreeCount = new HashMap<>();   //   ==> O(U) Time / Space
        int maxDegree = 0;
        for (int d : degree) {
            degreeCount.put(d, degreeCount.getOrDefault(d, 0) + 1);
            maxDegree = Math.max(maxDegree, d);
        }
     
        
        int[] count = new int[2 * maxDegree + 1]; 
        
        for (int d1 : degreeCount.keySet()) {                // O(E)-time  (seems to be O(U ^ 2))
            for (int d2 : degreeCount.keySet()) {
                count[d1 + d2] += (d1 == d2) ? degreeCount.get(d1) * (degreeCount.get(d1)- 1) 
                                             : degreeCount.get(d1) * degreeCount.get(d2);
            }
        }
        for (int i = 0; i < count.length; i++) count[i] /= 2;      // each pair is counted twice
        
    
        for (int e : edgeCount.keySet()) {            // O(E)-time
            int u = e / n;
            int v = e % n;     
            
            count[degree[u] + degree[v]]--;
            count[degree[u] + degree[v] - edgeCount.get(e)]++;
        }
        
        for (int i = count.length - 2; i >= 0; i--) {  // O(U)-time 
            count[i] += count[i+1];
        }
     
        
        int[] res = new int[queries.length];           // O(Q)-time
        for (int q = 0; q < queries.length; q++) {
            res[q] = ((queries[q] + 1) >= count.length) ? 0 : count[queries[q] + 1];
        }
        return res;
    }
}
