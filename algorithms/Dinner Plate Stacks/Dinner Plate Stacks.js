/**
 * @param {number} capacity
 */
var DinnerPlates = function(capacity) {
    this.capacity = capacity;
    this.stacks = [];
};

/** 
 * @param {number} val
 * @return {void}
 */
DinnerPlates.prototype.push = function(val) {
    var needNewStack = true
    for (var i = 0; i < this.stacks.length; i++) {
        if (this.stacks[i].length < this.capacity) {
            this.stacks[i].push(val);
            needNewStack = false;
            break;
        }
    }
    
    if (needNewStack) {
        this.stacks.push([val]);
    }
    
};

/**
 * @return {number}
 */
DinnerPlates.prototype.pop = function() {
    var val = -1;
    for (var i = this.stacks.length - 1; i >= 0; i--) {
        if (this.stacks[i].length > 0) {
            val = this.stacks[i].pop();
            break;
        }
    }
    return val;
};

/** 
 * @param {number} index
 * @return {number}
 */
DinnerPlates.prototype.popAtStack = function(index) {
    // console.log(index, this.stacks, ...this.stacks[index])
    var val = -1;
    if (this.stacks[index] && this.stacks[index].length > 0) {
        val = this.stacks[index].pop()
    }
    return val;
};

/** 
 * Your DinnerPlates object will be instantiated and called as such:
 * var obj = new DinnerPlates(capacity)
 * obj.push(val)
 * var param_2 = obj.pop()
 * var param_3 = obj.popAtStack(index)
 */
