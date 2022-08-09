var shortestPathLength = function(graph) {
  let n = graph.length, fullBitmask = (1 << n) - 1;
  let queue = [], visited = new Set();
  for (var i = 0; i < n; i++) {
    queue.push([i, 1 << i]);
    visited.add(`${i},${1 << i}`);
  }

  let steps = 0;
  while (queue.length) {
    let next = [];
    while (queue.length) {
      let [node, bitmask] = queue.pop();
      if (bitmask === fullBitmask) return steps;
      for (var neighbor of graph[node]) {
        let newBitmask = bitmask | (1 << neighbor);
        if (!visited.has(`${neighbor},${newBitmask}`)) {
          next.push([neighbor, newBitmask]);
          visited.add(`${neighbor},${newBitmask}`);
        }
      }
    }
    queue = next;
    steps++;
  }
};
