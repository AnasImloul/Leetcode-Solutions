class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        int[] inDegree = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            graph.put(i, new HashSet<Integer>());
        }
        
        for (int[] pair : prerequisites) {
            graph.get(pair[1]).add(pair[0]);
            inDegree[pair[0]]++;
        }
        
        // BFS - Kahn's Algorithm - Topological Sort
        Queue<Integer> bfsContainer = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                bfsContainer.add(i);    
            }
        }
        
        int count = 0;
        int[] ans = new int[numCourses];
        while (!bfsContainer.isEmpty()) {
            int curr = bfsContainer.poll();
            ans[count++] = curr;
            for (Integer num : graph.get(curr)) {
                inDegree[num]--;
                if (inDegree[num] == 0) {
                    bfsContainer.add(num);
                }
            }
        }
        
        if (count < numCourses) {
            return new int[] {};
        } else {
            return ans;
        }
    }
}
