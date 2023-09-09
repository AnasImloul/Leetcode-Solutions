// Runtime: 382 ms (Top 100.0%) | Memory: 129.94 MB (Top 57.1%)

var LUPrefix = function(n) {
    let q = new Array(n).fill(0);
    this.q = q;
    this.f = 0; //"f" is front of queue
};

//O(1)
LUPrefix.prototype.upload = function(video) {
    this.q[video - 1] = 1;
};

//O(n)
LUPrefix.prototype.longest = function() {
    while(this.q[this.f] && this.f < this.q.length) {
        this.f += 1;
    }
    return this.f;
};