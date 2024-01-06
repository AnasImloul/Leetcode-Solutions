// Runtime: 154 ms (Top 77.78%) | Memory: 53.40 MB (Top 88.89%)

var OrderedStream = function(n) {
    this.pointer = 0;
    this.streamArray = new Array(n).fill(undefined);
};
OrderedStream.prototype.insert = function(idKey, value) {
    this.streamArray[idKey-1] = value;
    if(this.streamArray[this.pointer] === undefined){
        return [];
    }else{
        const result = [];
        while(this.streamArray[this.pointer] !== undefined){
            result.push(this.streamArray[this.pointer]);
            this.pointer++;
        }
        return result;
    }
};
