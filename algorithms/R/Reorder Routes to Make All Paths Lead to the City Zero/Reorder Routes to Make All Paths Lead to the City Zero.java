/* 
My thought process
So here we can first actually build the graph and I uses a List<List<integer>> for it.
Here if we are having parent->child, then we take the sign as +ve and if vice versa we consider it as negative.
For traditional dfs, we need to keep track of the visited node thus we declare a boolean array for it.
Now do the dfs from node 0.

So the dfs function actually looks for the parent->child relation node and this has to be reversed. So count of parent->child relation is tracked here and the count is returned.

So we looks for the neighbours of the current node and traverse throught it. Then we check whether we already visited it, if no then update the count + do the dfs with the current child + add 1 if the child > 0, ie from parent -> child  or 0 ie then it  will be child -> parent.

Finally return the count and thats the problem.
*/


// 1. Convert the given into graph
// 2. Do the dfs and look for the forward direction.
// 3. Count of forward direction will give our answer.

class Solution {
    public int minReorder(int n, int[][] connections) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i=0; i<n; i++) {
            adj.add(new LinkedList<>());
        }
        for (int [] c:connections) {
            adj.get(c[0]).add(c[1]);
            adj.get(c[1]).add(-c[0]);
        }
        boolean [] visited = new boolean[n];
        return dfs(adj, visited, 0);
    }
    public int dfs(List<List<Integer>>adj, boolean [] visited, int v) {
        int reOrderCount = 0;
        visited[v] = true;
        List<Integer> children = adj.get(v);
        for (Integer child: children) {
            if (!visited[Math.abs(child)])
                reOrderCount += dfs(adj, visited, Math.abs(child)) + (child > 0 ? 1:0);
        }
        return reOrderCount;
    }
}
