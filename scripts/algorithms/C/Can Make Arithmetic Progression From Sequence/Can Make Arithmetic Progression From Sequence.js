// Runtime: 117 ms (Top 17.41%) | Memory: 42.3 MB (Top 65.96%)
var canMakeArithmeticProgression = function(arr) {
    arr.sort(function(a,b){return a-b});
    var dif = arr[1] - arr[0];
    for(var i=2;i<arr.length;i++){
        if(arr[i]-arr[i-1] !== dif){
            return false;
        }
    }
    return true;
};