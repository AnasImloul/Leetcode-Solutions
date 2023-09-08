// Runtime: 146 ms (Top 33.3%) | Memory: 51.13 MB (Top 62.5%)

var minimumTotalPrice = function(n, edges, price, trips) {
  let graph = Array(n).fill(0).map(() => []);
  for (let [a, b] of edges) {
    graph[a].push(b);
    graph[b].push(a);
  }
  let totalPrice = Array(n).fill(0);
  for (let [start, end] of trips) {
    let path = makeTrip(start, end);
    for (let node of path) {
      totalPrice[node] += price[node];
    }
  }
  let memo = new Map();
  return dfs(0, false, -1);
  
  function dfs(node, parentIsHalfPrice, parent) { // dfs with memoization to find the lowest price  
    let key = `${node},${parentIsHalfPrice},${parent}`;
    if (memo.has(key)) return memo.get(key);

    if (parentIsHalfPrice) {
      let ans = totalPrice[node];
      for (let nei of graph[node]) {
        if (nei === parent) continue;
        ans += dfs(nei, false, node);
      }
      memo.set(key, ans);
      return ans;
    }
    
    let takeHalfPrice = totalPrice[node] / 2, noHalfPrice = totalPrice[node];
    for (let nei of graph[node]) {
      if (nei === parent) continue;
      takeHalfPrice += dfs(nei, true, node);
      noHalfPrice += dfs(nei, false, node);
    }
    let ans = Math.min(takeHalfPrice, noHalfPrice);
    memo.set(key, ans);
    return ans;
  }
  
  function makeTrip(start, end) { // bfs to find the path from start to end
    let queue = [[start, [start]]], seen = Array(n).fill(0);
    seen[start] = 1;
    while (queue.length) {
      let [node, path] = queue.shift();
      if (node === end) return path;
      for (let nei of graph[node]) {
        if (seen[nei]) continue;
        seen[nei] = 1;
        queue.push([nei, [...path, nei]]);
      }
    }
  }
};