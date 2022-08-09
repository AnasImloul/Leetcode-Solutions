var minimumLines = function(stockPrices) {
   if(stockPrices.length<=1) return 0;
    stockPrices.sort((a,b)=>a[0]-b[0])
    var dates = stockPrices.map(el=>el[0]);
    var price = stockPrices.map(el=>el[1]);  
    var count = 0
    for(var i=0;i<dates.length-2;i++){
       var area1 = BigInt(price[i+1]-price[i]) * BigInt(dates[i+2]-dates[i+1]);
       var area2 = BigInt(dates[i+1]-dates[i])* BigInt(price[i+2]-price[i+1]);
        if(area1!==area2 ) {
            count++;
        } 
    }   
    return count+1;
};


