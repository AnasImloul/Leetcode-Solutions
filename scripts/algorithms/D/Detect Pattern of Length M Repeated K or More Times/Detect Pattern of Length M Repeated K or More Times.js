// Runtime: 48 ms (Top 83.72%) | Memory: 41.90 MB (Top 51.16%)

var containsPattern = function(arr, m, k) {
    for(let i=m, cnt=0; i<arr.length; i++){
        if(arr[i]!=arr[i-m]) cnt=0;
        else if(++cnt==m*(k-1)) return true;
    }
    return false;
};
