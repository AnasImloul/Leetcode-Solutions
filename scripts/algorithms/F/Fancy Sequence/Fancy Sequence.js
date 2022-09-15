// Runtime: 7163 ms (Top 34.61%) | Memory: 115.6 MB (Top 69.23%)
var Fancy = function() {
    this.sequence = [];
    this.appliedOps = [];
    this.ops = [];
    this.modulo = Math.pow(10, 9) + 7;
};

/**
 * @param {number} val
 * @return {void}
 */
Fancy.prototype.append = function(val) {
    this.sequence.push(val);
    this.appliedOps.push(this.ops.length);
};

/**
 * @param {number} inc
 * @return {void}
 */
Fancy.prototype.addAll = function(inc) {
    this.ops.push(['add', inc]);
};

/**
 * @param {number} m
 * @return {void}
 */
Fancy.prototype.multAll = function(m) {
    this.ops.push(['mult', m]);
};

/**
 * @param {number} idx
 * @return {number}
 */
Fancy.prototype.getIndex = function(idx) {
    if (idx >= this.sequence.length) {
        return -1;
    }

    while (this.appliedOps[idx] < this.ops.length) {
        const [operation, value] = this.ops[this.appliedOps[idx]];
        this.appliedOps[idx]++;

        if (operation === 'mult') {
            this.sequence[idx] = (this.sequence[idx] * value) % this.modulo;
        }

        if (operation === 'add') {
            this.sequence[idx] = (this.sequence[idx] + value) % this.modulo;
        }
    }

    return this.sequence[idx];
};

/**
 * Your Fancy object will be instantiated and called as such:
 * var obj = new Fancy()
 * obj.append(val)
 * obj.addAll(inc)
 * obj.multAll(m)
 * var param_4 = obj.getIndex(idx)
 */