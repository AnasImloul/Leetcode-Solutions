// Runtime: 196 ms (Top 63.64%) | Memory: 80.90 MB (Top 9.09%)

/**
 * @param {number[]} nums
 * @param {number[]} moveFrom
 * @param {number[]} moveTo
 * @return {number[]}
 */
var relocateMarbles = function(nums, moveFrom, moveTo) {
let positions = new Map();

  // Initialize the positions map with the initial marbles' positions
  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    positions.set(num, num);
  }

  // Perform the movements
  for (let i = 0; i < moveFrom.length; i++) {
    const from = moveFrom[i];
    const to = moveTo[i];

    // Move the marble from position moveFrom[i] to position moveTo[i]
    if (positions.has(from)) {
      const marble = positions.get(from);
      positions.delete(from);
      positions.set(to, marble);
    }
  }

  // Collect the occupied positions
  const result = [...positions.keys()].sort((a, b) => a - b);

  return result;
};
