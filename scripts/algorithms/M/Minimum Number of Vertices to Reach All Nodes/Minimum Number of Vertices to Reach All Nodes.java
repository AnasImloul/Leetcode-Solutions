// Runtime: 18 ms (Top 43.75%) | Memory: 119 MB (Top 77.96%)
class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {

        int[] indegree = new int[n];

        for(List<Integer> edge : edges) {
            indegree[edge.get(1)]++;
        }

        List<Integer> result = new ArrayList<>();

        for(int i=0; i<n;i ++) {
            if(indegree[i]==0)
                result.add(i);
        }

        return result;
    }
}