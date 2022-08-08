var numberOfSteps = function(num) {
    let steps = 0
    while (num > 0) {
        if (num % 2 === 0) {
            num = num/2
            steps++
        }
        
        if (num % 2 === 1) {
            num--
            steps++
        }
    }
    
    return steps
    
};
