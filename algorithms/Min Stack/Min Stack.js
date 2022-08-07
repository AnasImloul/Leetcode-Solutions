var MinStack = function() {
    this.stack = [];
    this.min = [];
};

MinStack.prototype.push = function(val) {
    this.stack.push(val);

    const lastMin = this.min[this.min.length - 1];

    if (lastMin === undefined || val < lastMin) {
        this.min.push(val);
    } else {
        this.min.push(lastMin);
    }
};

MinStack.prototype.pop = function() {
    this.stack.pop();
    this.min.pop();
};

MinStack.prototype.top = function() {
    return this.stack[this.stack.length - 1];
};

MinStack.prototype.getMin = function() {
    return this.min[this.min.length - 1];
};
