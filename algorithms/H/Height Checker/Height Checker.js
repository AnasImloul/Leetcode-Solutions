var heightChecker = function(heights) {
  let count = 0;
  const orderedHeights = [...heights].sort((a, b) => a-b)

  for (let i = 0; i < heights.length; i++) {
    heights[i] !== orderedHeights[i] ? count++ : null
  }

  return count
};
