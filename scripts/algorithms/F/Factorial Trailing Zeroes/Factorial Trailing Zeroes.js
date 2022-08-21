// Runtime: 110 ms (Top 31.72%) | Memory: 41.9 MB (Top 87.38%)

var trailingZeroes = function(n) {
    let count=0
   while(n>=5){
       count += ~~(n/5)
       n= ~~(n/5)
   }
    return count
};