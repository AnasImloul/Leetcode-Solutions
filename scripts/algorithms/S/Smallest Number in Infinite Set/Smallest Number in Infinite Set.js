var SmallestInfiniteSet = function() {
    const s = new Set();
    this.s  = s;
    for(let i = 1; i <= 1000; i++) s.add(i);
};

/**
 * @return {number}
 */
SmallestInfiniteSet.prototype.popSmallest = function() {
    const min = Math.min(...Array.from(this.s));
    this.s.delete(min);
    return min;
};

/** 
 * @param {number} num
 * @return {void}
 */
SmallestInfiniteSet.prototype.addBack = function(num) {
    this.s.add(num);
};

/** 
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * var obj = new SmallestInfiniteSet()
 * var param_1 = obj.popSmallest()
 * obj.addBack(num)
 */
