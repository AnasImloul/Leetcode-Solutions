// Runtime: 50 ms (Top 86.19%) | Memory: 43.00 MB (Top 14.55%)

var sumZero = function(n) {
  var num = Math.floor(n/2); 
  var res = [];

  for(var i=1;i<=num;i++){
      res.push(i,-i)
     } 

  if(n%2!==0){
    res.push(0)
  }
  
  return res 
}
