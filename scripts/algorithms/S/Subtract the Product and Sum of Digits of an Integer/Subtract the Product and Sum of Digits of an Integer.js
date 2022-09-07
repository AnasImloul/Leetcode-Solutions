// Runtime: 76 ms (Top 70.55%) | Memory: 42 MB (Top 76.90%)

var subtractProductAndSum = function(n) {
  let product=1,sum=0
  n=n.toString().split('')
  n.forEach((x)=>{
   product *=parseInt(x)
   sum +=parseInt(x)
  }
  )
    return product-sum
  };
