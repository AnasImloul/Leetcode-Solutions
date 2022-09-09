// Runtime: 216 ms (Top 17.69%) | Memory: 50.1 MB (Top 69.23%)
var CustomStack = function(maxSize) {
    this.stack = new Array(maxSize).fill(-1);
    this.maxSize = maxSize;
    this.size = 0;
};

CustomStack.prototype.push = function(x) {
    if(this.size < this.maxSize){
        this.stack[this.size] = x;
        this.size++;
    }
};

CustomStack.prototype.pop = function() {
    if(this.size > 0){
        this.size--;
        return this.stack[this.size];
    }
    return -1;
};

CustomStack.prototype.increment = function(k, val) {
    let count = k >= this.size ? this.size-1 : k-1;

    while(count >= 0){
        this.stack[count] += val;
        count--;
    }
};