// Runtime: 151 ms (Top 22.99%) | Memory: 94.00 MB (Top 86.21%)

class Solution {
    int longestPathValue = 1; // variable to store the length of the longest path

    public int longestPath(int[] parent, String s) {
        // create an adjacency list representation of the tree
        Map<Integer, List<Integer>> adj = new HashMap<>();
        for(int i = 1; i < parent.length; i++){
            int j = parent[i];
            adj.putIfAbsent(j, new LinkedList<>());
            adj.get(j).add(i);
        }
        // call dfs on the root of the tree
        dfs(0, adj, s);
        return longestPathValue;
    }

    public int dfs(int node, Map<Integer, List<Integer>> adj, String s){
        // if the node is a leaf node, return 1
        if(!adj.containsKey(node)) return 1;
        int max = 0, secondMax = 0;
        // for each neighbor of the node
        for(int nbrNode : adj.get(node)){
            int longestPathFromNbrNode = dfs(nbrNode , adj, s);
            // if the characters at the current node and its neighbor are the same, ignore the neighbor
            if(s.charAt(node) == s.charAt(nbrNode)) continue;
            // update max and secondMax with the longest path from the neighbor node
            if(longestPathFromNbrNode > max){
                secondMax = max;
                max = longestPathFromNbrNode;
            }else if(longestPathFromNbrNode > secondMax){
                secondMax = longestPathFromNbrNode;
            }
        }
        // update longestPathValue with the longest path that includes the current node
        longestPathValue = Math.max(longestPathValue, max+secondMax+1);
        return max+1;
    }
}

