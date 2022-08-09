var pathInZigZagTree = function(label) {
    //store highest and lowest value for each level
    let levels = [[1,1]] //to reduce space complexity we will fill the levels array with out output as we go
    let totalNodes = 1
    let nodesInLastRow = 1
    
    //Calculate which level the label lies in
    while (totalNodes < label) {      
        let lowest = totalNodes + 1
        
        nodesInLastRow = nodesInLastRow * 2
        totalNodes += nodesInLastRow
          
        let highest = totalNodes
        
        levels.push([lowest, highest])
    }
    

    let index = levels.length
    let childBoundaries = levels[levels.length -1]
    levels[levels.length -1] = label
    
    //Work bottom up, for each level, calculate the value based on the child and the child boundaries boundaries
    for (let i=levels.length-2; i>=0; i--) {
        let childLevel = i+2 //2 because i is index of 0, so 1 is to preset it to 1...n and then and second one is parent level
        let childValue = levels[i+1]    
        
        let inversionCalculation = Math.abs((childBoundaries[0] + childBoundaries[1]) - childValue)
        
        childBoundaries = levels[i]
        
        levels[i] = Math.floor(inversionCalculation/2)   
    }
    
    return levels
};
