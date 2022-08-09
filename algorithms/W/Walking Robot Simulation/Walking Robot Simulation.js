/**
 * @param {number[]} commands
 * @param {number[][]} obstacles
 * @return {number}
 */
var robotSim = function(commands, obstacles) {  
  let result = 0;
  let currentPosition = [0, 0];
  let currentDirection = 'top';
  const mySet = new Set();
  
  // This is to have a O(1) check instead of doing a linear scan
  obstacles.forEach(obs => {
    mySet.add(`${obs[0]},${obs[1]}`);
  }); // O(m)
  
  for (let i = 0; i < commands.length ; i++) { // O(n)
    const move = commands[i];
    if (move === -1) {
      if (currentDirection === 'top') {
        currentDirection = 'right';
      } else if (currentDirection === 'right') {
        currentDirection = 'down';
      } else if (currentDirection === 'down') {
        currentDirection = 'left';
      } else {
        currentDirection = 'top';
      }
    }
    
    if (move === -2) {
      if (currentDirection === 'top') {
        currentDirection = 'left';
      } else if (currentDirection === 'left') {
        currentDirection = 'down';
      } else if (currentDirection === 'down') {
        currentDirection = 'right';
      } else {
        currentDirection = 'top';
      }
    }
    
    if (move > 0) {
      for (let i = 0; i < move; i++) { O(move)
      const isY = (currentDirection === 'top' || currentDirection === 'down');
      const isPositive = (currentDirection === 'top' || currentDirection === 'right');
      
      const newPosition = [currentPosition[0] + (!isY ? isPositive? 1: -1 : 0), currentPosition[1] + (isY ? isPositive ? 1 : -1 : 0)];
      const positionString = `${newPosition[0]},${newPosition[1]}`;

      if (!mySet.has(positionString)) {
        currentPosition = newPosition;
        result = Math.max(result, (Math.pow(currentPosition[0], 2) + Math.pow(currentPosition[1], 2)));
      } else {
        break;
      }
    }
    }
  }
  return result;
};
