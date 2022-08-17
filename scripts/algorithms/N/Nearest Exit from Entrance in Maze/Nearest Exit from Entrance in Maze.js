const dir = [[0, 1], [0, -1], [1, 0], [-1, 0]];
const WALKED = '-', WALL = '+', NO_EXIT = -1;

/**
 * @param {character[][]} maze
 * @param {number[]} entrance
 * @return {number}
 */
var nearestExit = function(maze, entrance) {
  const m = maze.length, n = maze[0].length;
  const [ey, ex] = entrance;
  maze[ey][ex] = WALKED;
  
  const queue = new Queue([[ey, ex, 0]]);
  while (queue.size()) {
    const [y, x, step] = queue.dequeue();
    
    for (const [dy, dx] of dir) {
      const ny = y + dy, nx = x + dx, nextStep = step + 1;
      const overBorder = ny < 0 || ny >= m || nx < 0 || nx >= n;
      if (overBorder) {
        continue;
      }
      if (maze[ny][nx] === WALKED || maze[ny][nx] === WALL) {
        continue;
      }
      const isExit = ny === 0 || ny === m - 1 || nx === 0 || nx === n - 1;
      if (isExit) {
        return nextStep;
      }
      
      maze[ny][nx] = WALKED;
      queue.enqueue([ny, nx, nextStep]);
    }
  }
  
  return NO_EXIT;
};

