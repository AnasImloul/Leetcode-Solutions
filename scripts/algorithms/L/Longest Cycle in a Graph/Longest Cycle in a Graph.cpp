// Runtime: 137 ms (Top 83.42%) | Memory: 90.50 MB (Top 95.59%)

class Solution {
 public:
  int longestCycle(vector<int>& edges) {
    int ans = -1; // Initialize the answer to -1
    int time = 1; // Initialize the current time step to 1
    vector<int> timeVisited(edges.size()); // Initialize a vector to store the time at which each node was first visited

    // Iterate through each node in the graph
    for (int i = 0; i < edges.size(); ++i) {
      if (timeVisited[i]) // If the node has already been visited, skip it
        continue;
      const int startTime = time; // Record the start time of the current traversal
      int u = i; // Initialize the current node to the ith node
      // Traverse the graph until the end of the path is reached or a visited node is encountered
      while (u != -1 && !timeVisited[u]) {
        timeVisited[u] = time++; // Record the current time step and increment time
        u = edges[u]; // Move to the next node in the path
      }
      // If a cycle is found that includes the current node, update the answer
      if (u != -1 && timeVisited[u] >= startTime)
        ans = max(ans, time - timeVisited[u]);
    }

    return ans; // Return the length of the longest cycle found
  }
};

