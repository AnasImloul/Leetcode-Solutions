var reverseOddLevels = function(root) {
    let level = 1;
    let queue = [root];
    while(queue.length>0){
        let next = [];
		// Pushing the nodes of the queue
        for(node of queue){
            if(node.left) next.push(node.left);
            if(node.right) next.push(node.right);
        }
		// If the level matches the even number then we have to reverse those values 
        if(level%2===0){
            let [i,j] = [0,queue.length-1]
            while(i<j){
                [queue[i].val,queue[j].val] = [queue[j].val,queue[i].val]
                i++;
                j--;
            }
        }
        queue = [...next];
        level++;
    }
    return root;
};