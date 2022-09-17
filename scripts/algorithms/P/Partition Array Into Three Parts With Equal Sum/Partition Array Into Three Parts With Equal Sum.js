// Runtime: 131 ms (Top 30.56%) | Memory: 46 MB (Top 85.19%)
var canThreePartsEqualSum = function(arr) {
    const length = arr.length;
    let sum =0, count = 0, partSum = 0;
    for(let index = 0; index < length; index++) {
        sum += arr[index];
    }
    if(sum%3 !== 0) return false;
    partSum = sum/3;
    sum = 0;
    for(let index = 0; index < length; index++) {
        sum += arr[index];
        if(sum === partSum){
            count++;
            sum = 0;
            if(count == 2 && index < length-1) return true;
        }
    }
    return false;
};