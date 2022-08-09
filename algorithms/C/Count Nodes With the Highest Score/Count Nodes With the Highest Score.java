class Solution {
    long max = 0, res = 0;
    public int countHighestScoreNodes(int[] parents) {
        Map<Integer, List<Integer>> hm = new HashMap();
        for(int i = 0; i < parents.length; i++) {   // build the tree
            hm.computeIfAbsent(parents[i], x ->new ArrayList<>()).add(i);
        }
        dfs(0, parents.length, hm); // traverse the tree to get the result
        return (int)res;
    }
    int dfs(int s, int n, Map<Integer, List<Integer>> hm) {
        int sum = 1;
        long mult = 1L;
        for(int child : hm.getOrDefault(s, new ArrayList<>())) {
            int count = dfs(child, n, hm); // subtree node count
            sum += count;
            mult *= count; // multiply the result by children size
        }     
        mult *= (s == 0 ? 1L : n - sum); // multiply the result by remain size except self and children size(the nodes through parent)
        if(mult > max) {
            max = mult;
            res = 1;
        } else if (mult == max) {
            res++;
        }
        return sum; // return the node count of the tree rooted at s
    }
}
