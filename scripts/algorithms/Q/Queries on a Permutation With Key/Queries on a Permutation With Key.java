// Runtime: 15 ms (Top 39.19%) | Memory: 43.3 MB (Top 49.82%)
class Solution {
    public int[] processQueries(int[] queries, int m) {
        int[] results = new int[queries.length];
        ArrayList<Integer> permutations = new ArrayList<Integer>();

        // Filling the permuations array with numbers.
        for (int i = 0; i < m; i++)
            permutations.add(i+1);

        // Looping on the queries & checking their index in the permuations
        for (int i = 0; i < queries.length; i++) {
            int query = queries[i];
            for (int j = 0; j < permutations.size(); j++)
                if (permutations.get(j) == query) {
                    results[i] = j;
                    int temp = permutations.get(j);
                    permutations.remove(j);
                    permutations.add(0, temp);
                    break;
                }
        }

        return results;

    }
}