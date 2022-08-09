
function fastDiameter(node) {
    if(node == null) {
        let pair = new Array(2).fill(0)
        pair[0] = 0
        pair[1] = 0
        return pair
    }
    
    let leftPair = fastDiameter(node.left)
    let rightPair = fastDiameter(node.right)
    
    let leftDiameter = leftPair[0]
    let rightDiameter = rightPair[0]
    
    let height = leftPair[1] + rightPair[1] + 1
    
    let maxDiameter = Math.max(leftDiameter,rightDiameter,height)
    
    let maxHeight = Math.max(leftPair[1],rightPair[1]) + 1
    
    return [maxDiameter,maxHeight]
}

// diameter --> number of edges between two end nodes
var diameterOfBinaryTree = function(root) {
    
    let pair = fastDiameter(root)
    
    return pair[0]-1
};
