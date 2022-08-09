var RangeModule = function() {
    this.ranges = []
};

/** 
 * @param {number} left 
 * @param {number} right
 * @return {void}
 */
//Time: O(logN)
RangeModule.prototype.addRange = function(left, right) {
    const lIdx = this.findIndex(left), rIdx = this.findIndex(-right)
    if (lIdx === this.ranges.length) {
        this.ranges.push(left)
        this.ranges.push(-right)
    } else if (this.ranges[lIdx] < 0 && (this.ranges[rIdx] > 0 || rIdx === this.ranges.length)) {
        this.ranges.splice(lIdx, rIdx - lIdx, -right)
    } else if (this.ranges[lIdx] < 0 && this.ranges[rIdx] < 0) {
        this.ranges.splice(lIdx, rIdx - lIdx)
    } else if (this.ranges[lIdx] > 0 && (this.ranges[rIdx] > 0 || rIdx === this.ranges.length)) {
        this.ranges.splice(lIdx, rIdx - lIdx, left, -right)
    } else if (this.ranges[lIdx] > 0 && this.ranges[rIdx] < 0) {
        this.ranges.splice(lIdx, rIdx - lIdx, left)   
    }
    return null
};

/** 
 * @param {number} left 
 * @param {number} right
 * @return {boolean}
 */
//Time: O(logN)
RangeModule.prototype.queryRange = function(left, right) {
    const lIdx = this.findIndex(left), rIdx = this.findIndex(-right)
    if (lIdx === this.ranges.length) return false
    if (lIdx + 2 < rIdx) return false
    if (lIdx === rIdx) {
        return this.ranges[lIdx] < 0
    } else if (lIdx + 1 === rIdx) {
        return this.ranges[lIdx] === left || this.ranges[lIdx] === -right
    } {
        return this.ranges[lIdx] === left && Math.abs(this.ranges[lIdx + 1]) === right
    }
};

/** 
 * @param {number} left 
 * @param {number} right
 * @return {void}
 */
//Time: O(logN)
RangeModule.prototype.removeRange = function(left, right) {
    let lIdx = this.findIndex(left), rIdx = this.findIndex(-right)
    if (lIdx === this.ranges.length) return null
    if (this.ranges[lIdx] < 0 && (this.ranges[rIdx] > 0 || rIdx === this.ranges.length)) {
        this.ranges.splice(lIdx, rIdx - lIdx, -left)
    } else if (this.ranges[lIdx] < 0 && this.ranges[rIdx] < 0) {
        this.ranges.splice(lIdx, rIdx - lIdx, -left, right)
    } else if (this.ranges[lIdx] > 0 && (this.ranges[rIdx] > 0 || rIdx === this.ranges.length)) {
        this.ranges.splice(lIdx, rIdx - lIdx)
    } else if (this.ranges[lIdx] > 0 && this.ranges[rIdx] < 0) {
        this.ranges.splice(lIdx, rIdx - lIdx, right)   
    }
    // console.log(this.ranges)
    return null
};

RangeModule.prototype.findIndex = function(number) {
    let l = 0, r = this.ranges.length
    while(l < r) {
        const m = l + ((r - l) >> 1)
        if (Math.abs(this.ranges[m]) > Math.abs(number)) {
            r = m
        } else if (Math.abs(this.ranges[m]) < Math.abs(number)) {
            l = m + 1
        } else {
            if (number < 0) {
                l = m + 1
            } else {
                r = m
            }
        }
    }
    return l
}

/** 
 * Your RangeModule object will be instantiated and called as such:
 * var obj = new RangeModule()
 * obj.addRange(left,right)
 * var param_2 = obj.queryRange(left,right)
 * obj.removeRange(left,right)
 */

