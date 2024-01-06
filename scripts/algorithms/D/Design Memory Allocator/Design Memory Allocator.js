// Runtime: 133 ms (Top 100.0%) | Memory: 49.80 MB (Top 100.0%)

/**
 * @param {number} n
 */
var Allocator = function(n) {
    this.memory = Array(n).fill(null)
};

/** 
 * @param {number} size 
 * @param {number} mID
 * @return {number}
 */
Allocator.prototype.allocate = function(size, mID) {
    let startIndex = -1

    // Find first available block, if one exists
    for (let i = 0; i < this.memory.length; i++) {
        const end = i + size
        let found = true

        if (end > this.memory.length) return -1

        for (let j = i; j < this.memory.length && j < end ; j++) {
            if (this.memory[j] !== null) {
                i = j
                found = false
                break
            }
        }

        if (found) {
            startIndex = i
            break
        }
    }

    // Return -1 if one cannot be found
    if (startIndex === -1) return -1

    // Calculate end range
    const endIndex = startIndex + size

    // Update memory range with value
    for (let i = startIndex; i < endIndex; i++) {
        this.memory[i] = mID
    }

    return startIndex
};

/** 
 * @param {number} mID
 * @return {number}
 */
Allocator.prototype.free = function(mID) {
    let count = 0

    // Full scan memory for matching value
    for (let i = 0; i < this.memory.length; i++) {
        if (this.memory[i] === mID) {
            this.memory[i] = null
            count++
        }
    }

    return count
};

/** 
 * Your Allocator object will be instantiated and called as such:
 * var obj = new Allocator(n)
 * var param_1 = obj.allocate(size,mID)
 * var param_2 = obj.free(mID)
 */
