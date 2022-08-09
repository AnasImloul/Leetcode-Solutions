var validArrangement = function(pairs) {
  let graph = {};
  let degrees = {}; // outdegree: positive, indegree: negative
  for (var [x, y] of pairs) {
    if (!graph[x]) graph[x] = [];
    graph[x].push(y);
    if (degrees[x] === undefined) degrees[x] = 0;
    if (degrees[y] === undefined) degrees[y] = 0;
    degrees[x]++;
    degrees[y]--;
  }
  let start = pairs[0][0];
  for (var [x] of pairs) {
    if (degrees[x] === 1) start = x; // one extra outdegree
  }
  let ans = [];
  dfs(start);

  function dfs(node) {
    while ((graph[node] || []).length) {
      let neighbor = graph[node].pop();
      dfs(neighbor);
      ans.push([node, neighbor]);
    }
  }
  return ans.reverse();
};
