
 var RangeFreqQuery = function(arr) {

    this.array = arr;
    this.subRangeSize = Math.sqrt(this.array.length) >> 0;
    this.subRangeFreqs = [];

    let freq = {};

    for(let i = 0; i < arr.length; i++) {

        const num = arr[i];
    
        if(i >= this.subRangeSize && i % this.subRangeSize === 0) {
            this.subRangeFreqs.push({...freq});
            freq = {};
        }
        
        freq[num] = (freq[num] || 0) + 1;        
    }

    this.subRangeFreqs.push(freq);

};

RangeFreqQuery.prototype.query = function(left, right, value) {

    let fr = 0;

    const leftIdx = left / this.subRangeSize >> 0, rightIdx = right / this.subRangeSize >> 0;

    for(let i = leftIdx; i <= rightIdx; i++) {
        fr += this.subRangeFreqs[i][value] || 0;
    }

    for(let i = leftIdx * this.subRangeSize; i < left; i++) {
        fr -= this.array[i] === value ? 1 : 0;
    }

    for(let i = right + 1; i < Math.min((rightIdx + 1) * this.subRangeSize, this.array.length); i++) {
        fr -= this.array[i] === value ? 1 : 0;
    }
    return fr;
};
