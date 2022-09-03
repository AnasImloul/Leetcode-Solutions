// Runtime: 95 ms (Top 56.92%) | Memory: 193.9 MB (Top 33.32%)
class Solution {
  public long countPairs(int n, int[][] edges) {
    //Building Graph
    ArrayList < ArrayList < Integer >> graph = new ArrayList < > ();
    for (int i = 0; i < n; i++) graph.add(new ArrayList < Integer > ());
    for (int arr[]: edges) {
      graph.get(arr[0]).add(arr[1]);
      graph.get(arr[1]).add(arr[0]);
    }
    boolean visited[] = new boolean[n];
    long res = 0;
    int prev = 0;
    int count[] = {
      0
    };
    for (int i = 0; i < graph.size(); i++) { // Running for loop on all connected components of graph
      if (visited[i] == true) continue; // if the node is alredy reached by any of other vertex then we don't need to terverse it again
      dfs(graph, i, visited, count);
      long a = n - count[0]; // (total - current count)
      long b = count[0] - prev; // (current count - prev )
      prev = count[0]; // Now Store count to prev
      res += (a * b);
    }
    return res;
  }
  void dfs(ArrayList < ArrayList < Integer >> graph, int v, boolean vis[], int count[]) {
    vis[v] = true;
    count[0]++; //for counting connected nodes
    for (int child: graph.get(v)) {
      if (!vis[child]) {
        dfs(graph, child, vis, count);
      }
    }
  }
}