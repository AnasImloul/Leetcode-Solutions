
var StockPrice = function() {
    this.stocksPrice=[]
    this.timesStamp=[]
    this.lastPrice=[0,0];
    this.maxPrice=Number.NEGATIVE_INFINITY
    this.minPrice=Number.POSITIVE_INFINITY
};

/** 
 * @param {number} timestamp 
 * @param {number} price
 * @return {void}
 */
StockPrice.prototype.update = function(timestamp, price) {  
    let index=this.timesStamp.indexOf(timestamp)
    if(index === -1) {
        this.timesStamp.push(timestamp)
        this.stocksPrice.push(price)
        this.maxPrice=Math.max(this.maxPrice, price)
        this.minPrice=Math.min(this.minPrice, price)
    } else {
        if(this.maxPrice === this.stocksPrice[index] || 
           this.minPrice === this.stocksPrice[index]) {
            this.stocksPrice[index]=price
            this.maxPrice=Math.max(...this.stocksPrice)
            this.minPrice=Math.min(...this.stocksPrice)
        } else {
            this.stocksPrice[index]=price
            this.maxPrice=Math.max(this.maxPrice, price)
            this.minPrice=Math.min(this.minPrice, price)
        }
    }
    
    if(timestamp >= this.lastPrice[0])  this.lastPrice=[timestamp, price] 
};

/**
 * @return {number}
 */
StockPrice.prototype.current = function() {
    return this.lastPrice[1];
};

/**
 * @return {number}
 */
StockPrice.prototype.maximum = function() {
    return this.maxPrice
};

/**
 * @return {number}
 */
StockPrice.prototype.minimum = function() {
    return this.minPrice
};

/** 
 * Your StockPrice object will be instantiated and called as such:
 * var obj = new StockPrice()
 * obj.update(timestamp,price)
 * var param_2 = obj.current()
 * var param_3 = obj.maximum()
 * var param_4 = obj.minimum()
 */