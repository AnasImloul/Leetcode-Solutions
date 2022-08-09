var maxSatisfied = function(customers, grumpy, minutes) {
    let left=0;
    let maxUnsatisfied=0;
    let curr=0;
    let satisfied=0;
    
	// finding the satisfied customers
    for(let i=0;i<customers.length;i++){
        if(grumpy[i]===0)satisfied+=customers[i];
    }
    
    // finding the maximum un-satisfied customers within the give timeframe
	// classic sliding window approach
    for(let i=0;i<customers.length;i++){
        if(grumpy[i]) curr+=customers[i];
        if(i-left+1>minutes){
            if(grumpy[left])curr-=customers[left]
            left++
        }   
        if(i-left+1===minutes){
            if(curr>max){
                maxUnsatisfied=curr
            }
        }
    }
	
    return satisfied + maxUnsatisfied;
};
