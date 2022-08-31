// Runtime: 62 ms (Top 95.56%) | Memory: 42 MB (Top 66.94%)
var integerBreak = function(n) {

       if(n == 2) return 1;
       if(n == 3) return 2;
       if(n == 4) return 4;

       let c = ~~(n/3);
       let d = n % 3;

       if(d === 0){
           return 3 ** c;
       }

       if(d === 1){
           return 3 ** (c-1) * 4;
       }

       if(d === 2){
           return 3 ** (c) * 2;
       }

};