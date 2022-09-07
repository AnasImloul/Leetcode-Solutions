// Runtime: 350 ms (Top 45.24%) | Memory: 74.4 MB (Top 26.19%)
var mostCompetitive = function(nums, k) {
  let nbToRemove = nums.length - k,stack=[];
  for (const num of nums) {
    while (num<stack[stack.length -1] && stack.length && nbToRemove) {
      stack.pop();
      nbToRemove--;
    }
    stack.push(num)
  }
  while ( nbToRemove ) {
    stack.pop();
    nbToRemove--;
  }
  return stack;
};