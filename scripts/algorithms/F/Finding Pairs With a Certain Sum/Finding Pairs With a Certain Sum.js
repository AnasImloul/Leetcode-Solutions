// Runtime: 1920 ms (Top 7.69%) | Memory: 104.2 MB (Top 15.38%)
function Counter(arr) {

    // input: array
    // output: corresponding occurrence-based dictionary

    let keyOccDict = {};

    arr.forEach(val => keyOccDict[val] = (keyOccDict[val] || 0) + 1);

    return keyOccDict;
}

var FindSumPairs = function(nums1, nums2) {
    this.arrA = nums1;
    this.arrB = nums2;

    // maintain mapping between distinct number and occurrence for array A
    this.dictA = Counter(this.arrA );

    // maintain mapping between distinct number and occurrence for array B
    this.dictB = Counter(this.arrB );

    return
};

FindSumPairs.prototype.add = function(index, val) {

    // update mapping for arrB

    let old_value = this.arrB[index];
    this.arrB[index] += val;
    let new_value = this.arrB[index];

    this.dictB[ old_value ] = this.dictB[old_value] - 1;
    this.dictB[ new_value ] = (this.dictB[new_value] || 0) + 1;

    return
};

FindSumPairs.prototype.count = function(tot) {

    /*
      Goal:

      Find the method count of a + b = total,
      where a comes from array A, and b comes from array B

      apply the concept learned from Leetcode #1 Two sum
      a + b = total <=> b = total - a

      speed-up by dictionary
    */

    let counter = 0;

    for( const [a, occ_a] of Object.entries(this.dictA) ){

        let b = tot - a;

        counter += occ_a * (this.dictB[b] || 0);

    }

    return counter;
};
