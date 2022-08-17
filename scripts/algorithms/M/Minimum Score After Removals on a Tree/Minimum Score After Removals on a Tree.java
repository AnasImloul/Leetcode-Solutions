
class Solution {
    public int minimumScore(int[] nums, int[][] edges) {
        
        // 1.) Compute the adjacency table. Contains all paths, (including to root, must be filtered out later).
        Map<Integer, List<Integer>> adjGraph = computeAdjGraph(edges);
        
        // 2.) Know compute the total Xors of each node DFS style.
        Map<Integer, Integer> xorMap = new HashMap<>();
        computeNodeXorDfs(0, -1, nums, xorMap, adjGraph);
        int rootXor = xorMap.get(0);
        
        // 3.) Before computing all XORs in O(N^2) fashion, we want to compute a list of nodes of ascendant, descendant relationships.
            // Here we have to chose a SET instead of a list -> else we will run into TLS, obviously there are some duplicates.
        Map<Integer, Set<Integer>> descendants = new HashMap<>();
        Set<Integer> rootChildren = computeDescendants(0, -1, descendants, adjGraph);
        
        // 4.) We can check now the parent <-> child relationships. 
            // Compute each node under the root (not the root itself) for the following conditions:
                // node_i is parent of node_j
                    // rootXor = total ^ node_i (removing node_i from total)
                    // xor1 = node_i^ node_j (removing node_j from node_i)
                    // xor2 = node_j
                // node_j is parent of node_i
                    // rootXor = total ^ node_j (removing node_j from total)
                    // xor1 = node_j^ node_i (removing node_i from node_j)
                    // xor2 = node_i
                // node_j & node_i belong to different parents.
                    // rootXor = total ^ node_j^ nodE_i (removing node_i & node_j from total)
                    // xor1 = node_i
                    // xor2 = node_j
        
        int minScore = Integer.MAX_VALUE;
        
        for(int i = 1; i < adjGraph.keySet().size(); i++){
            for(int j = i+1; j < adjGraph.keySet().size(); j++){
                // Is node_i parent of node_j
                if(descendants.get(i).contains(j)){
                    int rootXor1 =  rootXor ^ xorMap.get(i);
                    int xor1 = xorMap.get(i) ^ xorMap.get(j);
                    int xor2 = xorMap.get(j);
                    int maxValue = Math.max(rootXor1, Math.max(xor1, xor2));
                    int minValue = Math.min(rootXor1, Math.min(xor1, xor2));
                    minScore = Math.min(minScore, maxValue - minValue);
                } else if(descendants.get(j).contains(i)){
                    int rootXor1 =  rootXor ^ xorMap.get(j);
                    int xor1 = xorMap.get(j) ^ xorMap.get(i);
                    int xor2 = xorMap.get(i);
                    int maxValue = Math.max(rootXor1, Math.max(xor1, xor2));
                    int minValue = Math.min(rootXor1, Math.min(xor1, xor2));
                    minScore = Math.min(minScore, maxValue - minValue);
                } else {
                    int rootXor1 =  rootXor ^ (xorMap.get(i) ^ xorMap.get(j));
                    int xor1 = xorMap.get(i);
                    int xor2 = xorMap.get(j);
                    int maxValue = Math.max(rootXor1, Math.max(xor1, xor2));
                    int minValue = Math.min(rootXor1, Math.min(xor1, xor2));
                    minScore = Math.min(minScore, maxValue - minValue);
                }
            }
        }
        
        
        return minScore;
    }
    
    Set<Integer> computeDescendants(int src, int parent, Map<Integer, Set<Integer>> descendants, Map<Integer, List<Integer>> adjGraph){
        
        Set<Integer> childrenOfNode = new HashSet<>();
        
        for(int child : adjGraph.get(src)){
            if(child != parent){
                // add the child node
                childrenOfNode.add(child);
                // add all its children.
                childrenOfNode.addAll(computeDescendants(child, src, descendants, adjGraph));
            }    
        }
        
        descendants.put(src, childrenOfNode);
        return childrenOfNode;
    }
        
    int computeNodeXorDfs(int src, int parent, int[] nums, Map<Integer, Integer> xorMap, Map<Integer, List<Integer>> adjGraph){
        
        int srcXor = nums[src];
        
        for(int child : adjGraph.get(src)){
            if(child != parent)
                srcXor ^= computeNodeXorDfs(child, src, nums, xorMap, adjGraph);
        }
        
        xorMap.put(src, srcXor);
        return srcXor;
    }
    
    Map<Integer, List<Integer>> computeAdjGraph(int[][] edges){
     
        Map<Integer, List<Integer>> adjGraph = new HashMap<>();
        
        for(int[] edge : edges){
            int v1 = edge[0];
            int v2 = edge[1];
            
            if(!adjGraph.containsKey(v1)){
                adjGraph.put(v1, new ArrayList<>());
            }
            
            if(!adjGraph.containsKey(v2)){
                adjGraph.put(v2, new ArrayList<>());
            }
            adjGraph.get(v1).add(v2);
            adjGraph.get(v2).add(v1);
        }
        return adjGraph;
    }
}
