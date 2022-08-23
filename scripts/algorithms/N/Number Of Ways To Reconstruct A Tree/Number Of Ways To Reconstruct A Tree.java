// Runtime: 418 ms (Top 41.46%) | Memory: 133.9 MB (Top 9.76%)
class Solution {
    public int checkWays(int[][] pairs) {
        int result = 1;

        //Create adjacency list
        Map<Integer, Set<Integer>> edges = new HashMap<>();
        for (int[] pair: pairs) {
            edges.computeIfAbsent(pair[0], x->new HashSet<>()).add(pair[0]);
            edges.computeIfAbsent(pair[1], x->new HashSet<>()).add(pair[1]);
            edges.get(pair[0]).add(pair[1]);
            edges.get(pair[1]).add(pair[0]);
        }

        //Sort the edge lists based on their size
        List<Map.Entry<Integer, Set<Integer>>> edgesList = new ArrayList(edges.entrySet());
        Collections.sort(edgesList, (a,b)-> b.getValue().size() - a.getValue().size());

        List<Map.Entry<Integer, Set<Integer>>> previous = new ArrayList<>();

        // Now from each of the edges find the ways to create the tree
        for (Map.Entry<Integer, Set<Integer>> cur: edgesList) {
            //get the current edge set
            Set<Integer> currentSet = cur.getValue();
            //find the parent for the current set from the previously computed edge
            Map.Entry<Integer, Set<Integer>> parent = find(previous, currentSet);
            // if the parent is null
            if (parent==null) {
                // if you the current set do not match with the edges size then there is no way, return 0
                if (currentSet.size() != edges.size())
                    return 0;
            } else {
                Set<Integer> parentSet = parent.getValue();
                // if the current set do not contain everything from the parent then also return 0
                if (!parentSet.containsAll(currentSet)) return 0;
                // if the parent contains everything from the current set then return more than one ways
                if (parentSet.equals(currentSet)) result = 2;
            }
            // add the computed edge to previous list
            previous.add(cur);
        }

        // only one way
        return result;
    }

    Map.Entry<Integer, Set<Integer>> find(List<Map.Entry<Integer, Set<Integer>>> previous, Set<Integer> currentSet) {
        int i=previous.size()-1;
        while (i>=0) {
            Map.Entry<Integer, Set<Integer>> entry = previous.get(i--);
            if (currentSet.contains(entry.getKey())) return entry;
        }
        return null;
    }
}