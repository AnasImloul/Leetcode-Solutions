// Runtime: 96 ms (Top 39.69%) | Memory: 41.8 MB (Top 87.19%)
var rotateString = function(s, goal) {
   const n = s.length;
   for(let i = 0; i < n; i++) {
      s = s.substring(1) + s[0];
      if(s === goal) return true;
   }
   return false;
};