// Runtime: 159 ms (Top 100.00%) | Memory: 52 MB (Top 62.79%)
var rearrangeBarcodes = function(barcodes) {
    var result = [];
    var map = new Map();
    barcodes.forEach(n => map.set(n, map.get(n) + 1 || 1));
    let list = [...map.entries()].sort((a,b) => {return b[1]-a[1]})
    let i = 0; //list[i][0]=>number list[i][1]=>count of this number
    while(result.length!==barcodes.length){
        if(list[i][1]>0) result.push(list[i][0]), list[i][1]--;
        i++;
        if(list[i]===undefined) i = 0;
        if(list[0][1]-list[i][1]>=1&&result[result.length-1]!==list[0][0]) i = 0;
    } //list has sorted, so list[0] appeared most frequent
    return result;
};