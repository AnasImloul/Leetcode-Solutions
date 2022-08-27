// Runtime: 121 ms (Top 6.20%) | Memory: 43.8 MB (Top 29.46%)
var MapSum = function() {
    this.hashKeys = new Map();
    this.hashVals = new Map();
};

MapSum.prototype.insert = function(key, val) {
    let prefix = '';
    for (const str of key) {
        prefix += str;
        const hashKey = this.hashKeys.get(prefix) ?? new Set();
        hashKey.add(key);
        !this.hashKeys.has(prefix) && this.hashKeys.set(prefix, hashKey);
    }
    this.hashVals.set(key, val);
};

MapSum.prototype.sum = function(prefix) {
    const hashKey = this.hashKeys.get(prefix);
    if (!hashKey) return 0;
    let sum = 0;
    hashKey.forEach(key => sum += this.hashVals.get(key));
    return sum;
};