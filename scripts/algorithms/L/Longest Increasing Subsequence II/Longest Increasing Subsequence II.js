// Runtime: 150 ms (Top 91.3%) | Memory: 55.73 MB (Top 52.1%)

var lengthOfLIS = function(nums, k) {
  let max = Math.max(...nums), segTree = new SegmentTree(max + 1), ans = 0;
  for (let num of nums) {
    let maxLength = segTree.maxInRange(Math.max(num - k, 0), num - 1);
    segTree.update(num, maxLength + 1);
    ans = Math.max(ans, maxLength + 1);
  }
  return ans;
};

class SegmentTree {
  constructor(n) {
    this.size = n;
    this.segTree = Array(n * 2).fill(0);
  }
  update(index, val) {
    let n = this.size, idx = index + n;
    this.segTree[idx] = Math.max(this.segTree[idx], val);
    idx = Math.floor(idx / 2);

    while (idx > 0) {
      this.segTree[idx] = Math.max(this.segTree[idx * 2], this.segTree[idx * 2 + 1]);
      idx = Math.floor(idx / 2);
    }
  }
  maxInRange(left, right) {
    let n = this.size, max = 0;
    let left_idx = left + n, right_idx = right + n;
    // left must be even, right must be odd
    // when left is odd or right is even, this indicates partial coverage. 
    // in other words, the parent node will be covering a range outside of the range we are looking for.
    // so, we need to take the partial sum and move the pointers so that it has full coverage.
    while (left_idx <= right_idx) {
      if (left_idx % 2 === 1) {
        max = Math.max(max, this.segTree[left_idx]);
        left_idx++;
      }
      if (right_idx % 2 === 0) {
        max = Math.max(max, this.segTree[right_idx]);
        right_idx--;
      }
      left_idx = Math.floor(left_idx / 2);
      right_idx = Math.floor(right_idx / 2);
    }
    return max;
  }
}