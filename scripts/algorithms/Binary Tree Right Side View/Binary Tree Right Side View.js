var rightSideView = function(root) {
    if(!root) return [];
    let ans = [];
    let queue = [root];
	
    while(queue.length > 0){
        let queueLength = queue.length;
		
		// As we are giving priority to right node, 
		// first node will always be the one that we want in output 
        ans.push(queue[0].val);
		
        for(let i = 0;i<queueLength;i++){
			// Ignore TC of queue.shift (assuming we have queue implementation with O(1) TC)
            let current = queue.shift();
			
			// Always give priority to right node
            if(current.right) queue.push(current.right);
            if(current.left) queue.push(current.left);
        }
    }
    return ans;
};
