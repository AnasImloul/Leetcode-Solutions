// Runtime: 307 ms (Top 78.95%) | Memory: 57.2 MB (Top 34.87%)

var RecentCounter = function() {
    this.arr = [];
};

RecentCounter.prototype.ping = function(t) {
    this.arr.push(t);
    while(t > this.arr[0]+3000){
        this.arr.shift();
    }
    return this.arr.length;
};
