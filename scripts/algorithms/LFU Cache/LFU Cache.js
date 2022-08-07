/**
 * @param {number} capacity
 */
var LFUCache = function(capacity) {
    this.capacity = capacity;
    this.cache = [];
};

/** 
 * @param {number} key
 * @return {number}
 */
LFUCache.prototype.get = function(key) {
    let val = -1;
    if (!this.capacity) return val;
    const existIndex = this.cache.findIndex(item => item.key === key);
    if (existIndex > -1) {
        const item = this.cache[existIndex];
        val = item.value;
        item.count++;
        this.cache.splice(existIndex, 1);
        this.cache.unshift(item);
    }
    return val;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LFUCache.prototype.put = function(key, value) {
    if (!this.capacity) return;
    const existIndex = this.cache.findIndex(item => item.key === key);
    if (existIndex > -1) {
        // new item already exists，rewrite the value and increase count
        const existItem = this.cache[existIndex];
        existItem.value = value;
        existItem.count++;
        this.cache.splice(existIndex, 1);
        this.cache.unshift(existItem);
    } else {
        // new item doesn't exist
        if (this.cache.length === this.capacity) {
            // reach the capacity, need to clear LFU
            let lfuIndex = 0;
            let leastCount = this.cache[lfuIndex].count;
            for (let i = 1; i < this.cache.length; i++) {
                const item = this.cache[i];
                if (item.count <= leastCount) {
                    leastCount = item.count;
                    lfuIndex = i;
                }
            }
            this.cache.splice(lfuIndex, 1);
            // after clear LFU, push the new item
            this.cache.unshift({
                key,
                value,
                count: 1
            });
        } else {
            // new item can be pushed
            this.cache.unshift({
                key,
                value,
                count: 1
            });
        }
    }
};

/** 
 * Your LFUCache object will be instantiated and called as such:
 * var obj = new LFUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
