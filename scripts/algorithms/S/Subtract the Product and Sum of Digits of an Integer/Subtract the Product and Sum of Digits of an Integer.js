
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
  
