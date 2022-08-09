var findSecondMinimumValue = function(root) {
  
    let firstMin=Math.min()
    let secondMin=Math.min()
    
    const que=[root]
    
    while(que.length){
        const node=que.shift()
        if(node.val<=firstMin){
            if(node.val<firstMin)secondMin=firstMin
            firstMin=node.val
        }else if(node.val<=secondMin){
            secondMin=node.val
        }
        if(node.left)que.push(node.left)
        if(node.right)que.push(node.right)
    }
    return secondMin===Math.min()?-1:secondMin
};
