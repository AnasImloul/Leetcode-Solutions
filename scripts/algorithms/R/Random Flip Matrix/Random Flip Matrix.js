// Runtime: 80 ms (Top 83.33%) | Memory: 61.30 MB (Top 16.67%)

var Solution = function(m, n) {
   this.length = m * n;
   this.range = new Array(this.length);
   this.n = n;
   this.pointer = 0;    
};

Solution.prototype.flip = function() {
    let limit = this.length - this.pointer - 1;
    let index = ~~(Math.random() * limit) + this.pointer;

    if(this.range[index] === undefined) this.range[index] = index;
    if(this.range[this.pointer] === undefined) this.range[this.pointer] = this.pointer;

    let tmp = this.range[index];
    this.range[index] = this.range[this.pointer];
    this.range[this.pointer] = tmp;

    let a = ~~(this.range[this.pointer] / this.n);
    let b = this.range[this.pointer] % this.n;

    this.pointer++;
    return[a, b];
};

Solution.prototype.reset = function() {
    this.pointer = 0;
};

