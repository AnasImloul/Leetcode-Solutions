// Runtime: 963 ms (Top 55.56%) | Memory: 101.7 MB (Top 5.32%)

var MedianFinder = function() {
    this.left = new MaxPriorityQueue();
  this.right = new MinPriorityQueue();
};

/**
 * @param {number} num
 * @return {void}
 */
MedianFinder.prototype.addNum = function(num) {
let { right, left } = this
  if (right.size() > 0 && num > right.front().element) {
    right.enqueue(num)
  } else {
    left.enqueue(num)
  }

  if (Math.abs(left.size() - right.size()) == 2) {
    if (left.size() > right.size()) {
      right.enqueue(left.dequeue().element)
    } else {
      left.enqueue(right.dequeue().element)
    }
  }
};

/**
 * @return {number}
 */
MedianFinder.prototype.findMedian = function() {
  let { left, right } = this
  if (left.size() > right.size()) {
    return left.front().element
  } else if(right.size() > left.size()) {
    return right.front().element
  } else{
      // get the sum of all
      return (left.front().element + right.front().element) / 2
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * var obj = new MedianFinder()
 * obj.addNum(num)
 * var param_2 = obj.findMedian()
 */