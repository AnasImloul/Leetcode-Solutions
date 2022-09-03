// Runtime: 346 ms (Top 50.00%) | Memory: 66.8 MB (Top 100.00%)
var goodTriplets = function(nums1, nums2) {
  let n = nums1.length, nums2_idx = Array(n);
  for (let i = 0; i < n; i++) nums2_idx[nums2[i]] = i;
  let idxs = Array(n);
  for (let i = 0; i < n; i++) idxs[i] = nums2_idx[nums1[i]];

  let smallerLeft = getSmallerLeft(idxs); // smallerLeft[i] = number of indices to the left of i smaller than idxs[i] in both nums1 and nums2
  let biggerRight = getBiggerRight(idxs); // biggerRight[i] = number of indices to the right of i bigger than idxs[i] in both nums1 and nums2
  let ans = 0;
  for (let i = 1; i < n - 1; i++) {
    ans += smallerLeft[i] * biggerRight[i];
  }
  return ans;
};

function getSmallerLeft(idxs) {
  let n = idxs.length, res = Array(n).fill(0);
  let segTree = new SegmentTree(n);
  for (let i = 0; i < n; i++) {
    res[i] = segTree.getSum(0, idxs[i] - 1);
    segTree.update(idxs[i], 1);
  }
  return res;
}

function getBiggerRight(idxs) {
  let n = idxs.length, res = Array(n).fill(0);
  let segTree = new SegmentTree(n);
  for (let i = n - 1; i >= 0; i--) {
    res[i] = segTree.getSum(idxs[i] + 1, n - 1);
    segTree.update(idxs[i], 1);
  }
  return res;
}

class SegmentTree {
  constructor(n) {
    this.size = n;
    this.segTree = Array(n * 2).fill(0);
  }
  update(index, val) {
    let n = this.size, idx = index + n;
    this.segTree[idx] += val;
    idx = Math.floor(idx / 2);

    while (idx > 0) {
      this.segTree[idx] = this.segTree[idx * 2] + this.segTree[idx * 2 + 1];
      idx = Math.floor(idx / 2);
    }
  }
  getSum(left, right) {
    let n = this.size, sum = 0;
    let left_idx = left + n, right_idx = right + n;
    // left must be even, right must be odd
    while (left_idx <= right_idx) {
      if (left_idx % 2 === 1) sum += this.segTree[left_idx++];
      if (right_idx % 2 === 0) sum += this.segTree[right_idx--];
      left_idx = Math.floor(left_idx / 2);
      right_idx = Math.floor(right_idx / 2);
    }
    return sum;
  }
}