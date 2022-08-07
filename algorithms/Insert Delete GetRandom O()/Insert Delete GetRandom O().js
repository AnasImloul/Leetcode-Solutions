var RandomizedSet = function() {
    this.ranArray = []
    this.ranObj = {}
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function(val) {
    if (this.ranObj[val] === undefined) {
        this.ranArray[this.ranArray.length] = val
        this.ranObj[val] = this.ranArray.length - 1
        return true
    } else {
        return false
    }
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function(val) {
    if (this.ranObj[val] === undefined) {
        return false
    } else {
        let tempLastVal = this.ranArray[this.ranArray.length - 1]
        let tempRemoveIndex = this.ranObj[val]
        this.ranObj[tempLastVal] = tempRemoveIndex
        this.ranArray[tempRemoveIndex] = tempLastVal
        this.ranArray.pop()
        delete this.ranObj[val]
        return true
    }
};

/**
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function() {
    return this.ranArray[Math.floor(Math.random()*this.ranArray.length)]
};

/** 
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
