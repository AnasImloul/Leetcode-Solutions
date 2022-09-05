// Runtime: 312 ms (Top 39.41%) | Memory: 57.1 MB (Top 18.96%)

var MyHashMap = function() {
    this.hashMap = [];
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
MyHashMap.prototype.put = function(key, value) {
    this.hashMap[key] = [key, value];
};

/**
 * @param {number} key
 * @return {number}
 */
MyHashMap.prototype.get = function(key) {
    return this.hashMap[key] ? this.hashMap[key][1] : -1;
};

/**
 * @param {number} key
 * @return {void}
 */
MyHashMap.prototype.remove = function(key) {
    delete this.hashMap[key];
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */