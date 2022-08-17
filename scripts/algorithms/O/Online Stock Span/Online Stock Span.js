var StockSpanner = function() {
    this.stack = [];
    this.idx = 0;
};

StockSpanner.prototype.next = function(price) {
    
	// keep Pop-ing if top element of stack is bigger than current price
    while(this.stack.length > 0 && this.stack[this.stack.length-1][0] <= price){
        this.stack.pop();
    }
    
	// if stack is empty after above operation
    if(this.stack.length === 0){
	
		// Push current price with index
        this.stack.push([price,this.idx]);
		
		// increment index - this is a tricky part
        this.idx++;
		
        return this.idx;
    }
    
	// caclulate distance from top element of stack and return
	
    const res = this.idx - this.stack[this.stack.length-1][1];
    this.stack.push([price,this.idx]);
    this.idx++;
    return res;
};

