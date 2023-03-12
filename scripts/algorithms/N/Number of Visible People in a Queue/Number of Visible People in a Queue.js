var visibleToRight = function(heights){
    const result = new Array(heights.length).fill(0)
    const stack = []

    let i = heights.length-1
    
    // loop from right to left
    while(i >= 0){ 
        let popCount = 0
        
        // Keep Popping untill top ele is smaller
        while(stack.length > 0 && stack[stack.length-1][0] < heights[i]){
			stack.pop()
            popCount+=1
        }
        
        /////////////////////
        /// After Popping ///
        ////////////////////
        
        // Case1: if ALL elements got popped
        if(stack.length === 0)
            result[i] = popCount // mark
        
        // Case2: if NO elements were popped
        else if(popCount === 0)
            result[i] = 1 // mark
            
        // Case3: if SOME elements were popped
        else
            result[i] = popCount+1 // mark
        
        // store
        stack.push([heights[i],popCount])
        
        i-=1
    }
    
    return result
}
var canSeePersonsCount = function(heights) {
    return visibleToRight(heights)
};
