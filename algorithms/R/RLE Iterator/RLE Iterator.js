var RLEIterator = function(encoding) {
    this.encoding = encoding
    // Pointer to count index
    this.index = 0
}

RLEIterator.prototype.next = function(n) {
    while (n > 0) {
        // Move to next count index when the current index is 0
        if (this.encoding[this.index] === 0) this.index += 2
        
        // Too many calls to next, return -1
        if (this.index >= this.encoding.length) return -1
        
        // n goes completely into count
        if (n <= this.encoding[this.index]) {
            this.encoding[this.index] -= n
            n = 0
        // count goes completely into n
        } else if (n > this.encoding[this.index]) {
            n -= this.encoding[this.index]
            this.encoding[this.index] = 0
        }
    }

    return this.encoding[this.index + 1]
}
