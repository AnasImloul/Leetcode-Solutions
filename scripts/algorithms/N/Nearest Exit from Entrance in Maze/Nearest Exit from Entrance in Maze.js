function nearestExit(maze, entrance) {
  const queue = []; // queue for bfs
  const empty = ".";
  const [height, width] = [maze.length, maze[0].length];
  const tried = [...Array(height)].map(() => Array(width).fill(false));
  const tryStep = (steps, row, col) => {
    // don't reuse once it's already been tried
    if (tried[row][col]) return;
    tried[row][col] = true;
    if (maze[row][col] !== empty) return; // blocked? i.e. can't step
    queue.push([steps, row, col]);
  };
  const edges = { right: width - 1, bottom: height - 1, left: 0, top: 0 };
  const trySteppableDirs = (steps, row, col) => {
    // try steppable directions
    if (col < edges.right) tryStep(steps, row, col + 1);
    if (row < edges.bottom) tryStep(steps, row + 1, col);
    if (col > edges.left) tryStep(steps, row, col - 1);
    if (row > edges.top) tryStep(steps, row - 1, col);
  };
  let steps = 1, [row, col] = entrance;
  tried[row][col] = true; // don't reuse the entrance
  trySteppableDirs(steps, row, col);
  while (queue.length > 0) { // bfs
    [steps, row, col] = queue.shift();
    // path to the edge found?
    if (col === edges.left || col === edges.right) return steps;
    if (row === edges.top || row === edges.bottom) return steps;
    trySteppableDirs(steps + 1, row, col);
  }
  // NO path to the edge found
  return -1;
}