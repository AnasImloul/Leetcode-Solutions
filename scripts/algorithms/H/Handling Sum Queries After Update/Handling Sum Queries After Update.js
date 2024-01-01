// Runtime: 300 ms (Top 33.33%) | Memory: 100.30 MB (Top 33.33%)

var handleQuery = function(nums1, nums2, queries) {
  const segmentTree = new SegmentTree(nums1, nums2);

  return queries.reduce((answers, [type, a, b]) => {
    switch (type) {
      case 1:
        segmentTree.query1(a, b);
        return answers;
      case 2:
        segmentTree.query2(a);
        return answers;
      default:
        answers.push(segmentTree.query3());
        return answers;
    }
  }, []);
};

class SegmentTree {
  flipped = [];
  counts = [];
  max = 0;
  total = 0;

  constructor(nums1, nums2) {
    this.max = nums1.length - 1;
    this.flipped = [...nums1, ...nums1].map(() => 0);
    this.counts = [...this.flipped];
    this.total = nums2.reduce((total, num) => total + num, 0);
    
    this.build(0, 0, nums1.length - 1, nums1);
  }

  build(idx, min, max, nums) {
    if (min === max) {
	  // leaf
      this.counts[idx] = nums[min];
      return this.counts[idx];
    }
    
    const mid = min + max >> 1;
    
    const leftCount = this.build(idx * 2 + 1, min, mid, nums);
    const rightCount = this.build(idx * 2 + 2, mid + 1, max, nums);
    
    this.counts[idx] = leftCount + rightCount;
    return this.counts[idx];
  }

  query1(l, r, idx = 0, min = 0, max = this.max) {
    // outside of range, do nothing
    if (min > r || max < l) return this.counts[idx];
    if (min === max) {
	  // leaf
      this.counts[idx] = 1 - this.counts[idx];
      return this.counts[idx];
    }
    
	// use the size to get the inverse of our child sums if we're flipped
    const size = max - min + 1;
    
    if (l <= min && r >= max) {
	  // range is covered, just update the flipped state
      this.flipped[idx] = 1 - this.flipped[idx];
      const leftCount = this.counts[idx * 2 + 1];
      const rightCount = this.counts[idx * 2 + 2];
      this.counts[idx] = this.flipped[idx]
        ? size - leftCount - rightCount
        : leftCount + rightCount;
      return this.counts[idx];
    }
    
	// range is partially covered, so we gotta update our children
    const mid = min + max >> 1;
    const leftCount = this.query1(l, r, idx * 2 + 1, min, mid);
    const rightCount = this.query1(l, r, idx * 2 + 2, mid + 1, max);
    this.counts[idx] = this.flipped[idx]
      ? size - leftCount - rightCount
      : leftCount + rightCount;
    return this.counts[idx];
  }

  query2(p) {
    this.total += this.counts[0] * p;
  }

  query3() {
    return this.total;
  }
}
