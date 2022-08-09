var ways = function(pizza, k) {
  const height = pizza.length;
  const width = pizza[0].length;
  const APPLE = 'A';

  const cache = {};
  const dfs = (slices, startRow, startCol) => {
    // if we cut the entire pizza return 0
    if (startRow >= height || startCol >= width) return 0;

    // see if the parameters of the DFS has already been seen
    // if i has been seen, return the value
    const key = [slices, startRow, startCol].join('-');
    if (cache[key]) return cache[key];

    // if there is only 1 slice left to be made
    // find out if there is an apple in the slice
    if (slices === 1) {
      for (let row = startRow; row < height; row++) {
        for (let col = startCol; col < width; col++) {
          if (pizza[row][col] === APPLE) {
            return cache[key] = 1;
          }
        }
      }
      return cache[key] = 0;
    }

    // create a variable to total the number of ways
    let totalWays = 0;
    // create a variable to see if we have found an apple
    let hasApple = false;
    // decrement the number of slices left to be made
    slices--;

    // try to cut horizontally checking if we have found an apple
    // if we have found an apple keep cutting every row after that row
    for (let row = startRow; row < height; row++) {
      // to find an apple we search the current row if it has an apple in it
      // this will only run as long as we have not found an apple and in a current column
      for (let col = startCol; col < width && !hasApple; col++) {
        if (pizza[row][col] === APPLE) {
          hasApple = true;
        }
      }

      // if we have found an apple cut the pizza horizontally
      if (hasApple) {
        totalWays += dfs(slices, row + 1, startCol);
      }
    }


    // same as above except this time we cut vertically
    hasApple = false;
    for (let col = startCol; col < width; col++) {
      for (let row = startRow; row < height && !hasApple; row++) {
        if (pizza[row][col] === APPLE) {
          hasApple = true;
        }
      }
      if (hasApple) {
        totalWays += dfs(slices, startRow, col + 1);
      }
    }

    // return the number of ways
    return cache[key] = totalWays % 1000000007;
  }
  return dfs(k, 0, 0);
};
