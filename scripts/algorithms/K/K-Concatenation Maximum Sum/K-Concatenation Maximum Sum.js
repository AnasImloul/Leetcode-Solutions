// Runtime: 134 ms (Top 27.59%) | Memory: 52.2 MB (Top 31.03%)
var kConcatenationMaxSum = function(arr, k) {
    var MOD = 1000000007;
    let sum = arr.reduce((a,b)=>a+b);
    if(k>1) arr.push(...arr);
    let temp = 0, result = 0;
     for(i=0;i<arr.length;i++){
          temp = Math.max(arr[i],arr[i]+temp);
          if(temp>result) result = temp;
        }
    return (sum>0&&k>2) ? (result+sum*(k-2))%MOD : result%MOD;
};