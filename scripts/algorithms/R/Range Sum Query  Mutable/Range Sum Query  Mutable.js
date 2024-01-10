// Runtime: 440 ms (Top 94.87%) | Memory: 100.70 MB (Top 60.26%)

// e.g: [1,2,5,7]
// the length of the segment tree will be the length of the array x2

//                               |leaf nodes
// segment tree array: [*,15,3,12,1,2,5,7]
//                        sums...|

// the first item will always be empty, the sum of all items is the second item.

// To get child nodes:
// Left child: idx * 2
// Right child: idx * 2 + 1

// To get parent node:
// Math.floor(idx / 2)

// n = nums.length

// NumArray: 
// this.segTree will be an array of size (n * 2)
// build segTree

// build: T.C - O(n), S.C - O(n * 2)
// Loop through from n to n * 2, filling second half of segTree with nums
// Loop through from n - 1 to 1 (pointer = i)
//   set segTree[i] equal the sum of the two children, segTree[i * 2] + segTree[i * 2 + 1]

// update: T.C - O(log(n)), S.C - O(1)
// start at leaf node, update segTree[index + n] to val
// Loop while index > 0
//   let left and right both be index
//   (remember left child is always even, right child is always odd)
//   if index is even, increment right by one 
//   else decrement left by one
//   update index to be parent, Math.floor(index / 2)
//   update segTree[index] to segTree[left] + segTree[right]

// sumRange: T.C - O(log(n)), S.C - O(1)
// Set left to left + n, right to right + n (leaf nodes)
// Loop while left is smaller than or equal to right
//  (to get the sum, left must be even and right must be odd)
//   If left is odd, add segTree[left] to sum, increment left.
//   If right is even, add segTree[right] to sum, decrement right.
//   Set left to Math.floor(left / 2)
//   Set right to Math.floor(right / 2)
// Return sum


// Why the left index must be even & right index must be odd:
    // when left is odd or right is even, this indicates partial coverage. 
    // in other words, the parent node will be covering a range outside of the range we are looking for.
    // so, we need to take the partial sum and move the pointers closer so that it has full coverage.


var NumArray = function(nums) {
  this.n = nums.length;
  this.segTree = new Array(this.n * 2);
  this.build(nums);
};

NumArray.prototype.build = function(nums) {
  let n = this.n;
  let j = 0;
  for (var i = n; i < n * 2; i++) {
    this.segTree[i] = nums[j];
    j++;
  }
  for (i = n - 1; i > 0; i--) {
    this.segTree[i] = this.segTree[i * 2] + this.segTree[i * 2 + 1];
  }
}

NumArray.prototype.update = function(index, val) {
  let n = this.n;
  index += n;
  this.segTree[index] = val;
  while (index > 1) {
    let left = index, right = index;
    if (index % 2 === 0) {
      right = index + 1;
    } else {
      left = index - 1;
    }
    index = Math.floor(index / 2);
    this.segTree[index] = this.segTree[left] + this.segTree[right];
  }
};

NumArray.prototype.sumRange = function(left, right) {
  let n = this.n;
  left += n, right += n;
  let sum = 0;
  while (left <= right) {
    if (left % 2 === 1) {
      sum += this.segTree[left];
      left++;
    }
    if (right % 2 === 0) {
      sum += this.segTree[right];
      right--;
    }
    left = Math.floor(left / 2);
    right = Math.floor(right / 2);
  }   
  return sum;
};
