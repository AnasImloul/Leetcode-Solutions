// Runtime: 335 ms (Top 91.3%) | Memory: 113.50 MB (Top 8.7%)

/**
 * @param {number} value
 * @param {number} k
 */
var DataStream = function(value, k) {
    this.k = k
    this.val = value

    this.length = 0 // Total number of elements in data stream
    this.count = 0 // Last elements which are equal to value
};

/** 
 * @param {number} num
 * @return {boolean}
 */
DataStream.prototype.consec = function(num) {
    this.length++

    if (num === this.val) this.count++
    else this.count = 0

    if (this.length < this.k) return false

    if (this.count >= this.k) return true
    return false
};

/** 
 * Your DataStream object will be instantiated and called as such:
 * var obj = new DataStream(value, k)
 * var param_1 = obj.consec(num)
 */
