// Runtime: 60 ms (Top 23.13%) | Memory: 60.00 MB (Top 7.01%)

var reverse = function(x) {
    let val = Math.abs(x)
    let res = 0
    while(val !=0){
         res = (res*10) + val %10
         val = Math.floor(val/10)
    }
    if(x < 0)res = 0 - res
    return (res > ((2**31)-1) || res < (-2)**31) ? 0 : res 
};
