// Runtime: 503 ms (Top 81.82%) | Memory: 93.70 MB (Top 13.64%)

var minAbsoluteDifference = function(nums, x) {
  if (x === 0) return 0;
  let n = nums.length, maxSegTree = new MaxSegmentTree(n);
  let arr = nums.map((num, idx) => [num, idx]).sort((a, b) => a[0] - b[0]);
  let minDiff = Infinity;
  for (let i = 0; i < n; i++) {
    let [num, idx] = arr[i];
    let maxLeft = maxSegTree.maxRange(0, idx - x);
    let maxRight = maxSegTree.maxRange(idx + x, n - 1);
    minDiff = Math.min(minDiff, num - maxLeft, num - maxRight);
    maxSegTree.update(idx, num);
  }
  return minDiff;
};

class MaxSegmentTree {
  constructor(n) {
    this.size = n;
    this.segTree = Array(n * 2).fill(-Infinity);
  }
  update(index, value) {
    let n = this.size, idx = index + n;
    this.segTree[idx] = value;
    idx = Math.floor(idx / 2);

    while (idx > 0) {
      this.segTree[idx] = Math.max(this.segTree[idx * 2], this.segTree[idx * 2 + 1]);
      idx = Math.floor(idx / 2);
    }
  }
  maxRange(left, right) {
    if (left > right) return -Infinity;
    let n = this.size, max = -Infinity;
    let left_idx = left + n, right_idx = right + n;
    while (left_idx <= right_idx) {
      if (left_idx % 2 === 1) max = Math.max(max, this.segTree[left_idx++]);
      if (right_idx % 2 === 0) max = Math.max(max, this.segTree[right_idx--]);
      left_idx = Math.floor(left_idx / 2);
      right_idx = Math.floor(right_idx / 2);
    }
    return max;
  }
}
