var PeekingIterator = function(iterator) {
    this.iterator = iterator
    this.curr = iterator.next()

};

PeekingIterator.prototype.peek = function() {
    return this.curr
};

PeekingIterator.prototype.next = function() {
    let temp = this.curr
    this.curr = this.iterator.next()
    return temp
};

PeekingIterator.prototype.hasNext = function() {
    return this.curr > 0   // the input iterator return -100000000 when next() after it run out of members, instead of return undefined.
};

