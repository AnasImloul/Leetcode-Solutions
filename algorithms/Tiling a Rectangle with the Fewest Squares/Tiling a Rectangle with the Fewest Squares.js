var tilingRectangle = function(n, m) {
  const queue = [[new Array(n).fill(0), 0]];
  while (true) {
    const [curr, numSquares] = queue.shift();
    let min = { height: Infinity, start: Infinity, end: Infinity }
    for (let i = 0; i < n; i++) {
      if (curr[i] < min.height) {
        min.height = curr[i];
        min.start = i;
        min.end = i + 1;
      } else if (curr[i] === min.height && min.end === i) {
        min.end++
      }
    }
    if (min.height === m) return numSquares;
    const largestSquare = Math.min(m - min.height, min.end - min.start);
    for (let sqWidth = largestSquare; sqWidth; sqWidth--) {
      const next = curr.slice();
      for (let i = min.start; i < min.start + sqWidth; i++) {
        next[i] += sqWidth;
      }
      queue.push([next, numSquares + 1]);
    }
  }
};
