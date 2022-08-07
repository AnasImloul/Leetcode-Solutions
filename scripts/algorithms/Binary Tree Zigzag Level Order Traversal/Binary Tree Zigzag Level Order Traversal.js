var zigzagLevelOrder = function(root) {
    let result = []
    if(root == null) return result
    
    let queue = []
    let leftToRight = true
    
    queue.push(root)
    
    while(queue.length != 0) {
        let qSize = queue.length
        let ans = []
        
        // Processing level
        for(let i=0;i<qSize;i++) {
            let front = queue.shift()
            
            let index = leftToRight ? i : qSize-i-1
            ans[index] = front.val
            
            if(front.left) queue.push(front.left)
            if(front.right) queue.push(front.right)
        }
        // changing order of operation
        leftToRight = !leftToRight
        
        result.push(ans)
    }
    
    return result
};
