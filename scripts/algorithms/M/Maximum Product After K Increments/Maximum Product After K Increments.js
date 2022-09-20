// Runtime: 2154 ms (Top 9.38%) | Memory: 125.7 MB (Top 6.25%)
var maximumProduct = function(nums, k) {
  let MOD = Math.pow(10, 9) + 7;

  // build a new minimum priority queue
  // LeetCode loads MinPriorityQueue by default, no need to implement again
  let queue = new MinPriorityQueue();
  for (let i = 0; i < nums.length; i++) {
    queue.enqueue(nums[i], nums[i]);
  }

  // To maximize the product, take the smallest element out
  // add 1 to it and add it back to the queue
  let count = 0;
  while (count < k && queue.size() > 0) {
    let {element, priority} = queue.dequeue();
    queue.enqueue(element + 1, priority + 1);
    count += 1;
  }

  // calculate the product
  let result = 1;
  let elements = queue.toArray().map((a) => a.element);
  for (let i = 0; i < elements.length; i++) {
    result = (result * elements[i]) % MOD;
  }

  return result;
};