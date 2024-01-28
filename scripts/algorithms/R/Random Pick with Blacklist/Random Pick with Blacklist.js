// Runtime: 253 ms (Top 88.89%) | Memory: 75.80 MB (Top 22.22%)

/**
 * @param {number} n
 * @param {number[]} blacklist
 */
var Solution = function(n, blacklist) {
    this.space = n - blacklist.length;
    this.map = {};

    blacklist.forEach((b, i) => {
        const next = this.space + i;

        const head = this.map[b] === undefined ? b : this.map[b];
        const tail = this.map[next] === undefined ? next : this.map[next];

        this.map[head] = tail;
        this.map[tail] = head;
    });
};

/**
 * @return {number}
 */
Solution.prototype.pick = function() {
    const result = Math.floor(Math.random() * this.space);
    return this.map[result] || result;
};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(n, blacklist)
 * var param_1 = obj.pick()
 */
