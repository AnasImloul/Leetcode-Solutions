// Runtime: 0 ms (Top 100.0%) | Memory: 43.10 MB (Top 12.5%)

class Solution {
    public List<Integer> mostVisited(int n, int[] rounds) {
        var start = rounds[0];
        var end = rounds[rounds.length - 1];   
        var res = new ArrayList<Integer>();
        if (start <= end) {
            for (int i = start; i <= end; i++) res.add(i);
        } else {
            for (int i = 1; i <= end; i++) res.add(i);
            for (int i = start; i <= n; i++) res.add(i);
        }
        return res;
    }
}
