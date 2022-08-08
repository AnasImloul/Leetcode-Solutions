var smallestFromLeaf = function(root) {
    
    if(root === null) return '';
    
    let queue = [[root, ''+giveCharacter(root.val)]];
    let leafLevelFound = false;
    let possibleSmallString = [];
    
    while(queue.length > 0){
        
        let currentLevelLength = queue.length;
        
        
        for(let i=0; i<currentLevelLength; i++){
            
            let [currentNode, currentPath] = queue.shift();
            
            if(currentNode.left === null && currentNode.right ===null){
                // as one of the test case is failing with this approacch - saying legth/depth of the path doesnt matter
                // even TOTAL (ASCII)SUM of letters also not matter - it should be dictionary first path
                // hence, no need of this logic and have to continue until all path discovered
                // So, instead removing - just never doing TRUE - hence it will continue exploring and putting all paths
                leafLevelFound = false; 
                possibleSmallString.push(currentPath); //.split("").reverse().join("")
            }
            
            if(!leafLevelFound){
                if(currentNode.left !== null) queue.push([currentNode.left,giveCharacter(currentNode.left.val)+currentPath]);
                if(currentNode.right !== null) queue.push([currentNode.right,giveCharacter(currentNode.right.val)+currentPath]);
            }
            
        }
        
        if(leafLevelFound) break; 
    }
    
    // console.log(possibleSmallString);
    possibleSmallString.sort();
    // console.log(possibleSmallString);
    return possibleSmallString[0];
    
};

function giveCharacter(num){
    return String.fromCharCode(num+97);
}
