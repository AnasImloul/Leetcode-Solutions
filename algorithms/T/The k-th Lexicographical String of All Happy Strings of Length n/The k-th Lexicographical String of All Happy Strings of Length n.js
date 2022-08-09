var getHappyString = function(n, k) {
    const arr = ['a','b','c'], finalArr = ['a','b','c'];
    let chr = '', str = '';
    if(finalArr[finalArr.length-1].length === n && finalArr[0].length === n ) {
        return finalArr[k-1] && finalArr[k-1].length === n ? finalArr[k-1] : '';
    }
    for(; finalArr.length < k || finalArr[0].length <= n;) {
        str = finalArr.shift();
        for(let index2 = 0; index2 < 3; index2++){
            chr = str[str.length-1];
            if(chr !== arr[index2]) {
                finalArr.push(str+arr[index2]);
            }
        }
        if(finalArr[finalArr.length-1].length === n && finalArr[0].length === n ) break;
    }
    return finalArr[k-1] ? finalArr[k-1] : '';
};
