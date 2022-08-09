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

