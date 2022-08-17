var rangeSumBST = function(root, low, high) {
    let sum = 0;
    const summer = (root) => {
        if(!root) {
            return;
        }
		
        sum = root.val >= low && root.val <= high ? root.val + sum : sum;
        
        summer(root.left)
        summer(root.right)
    }
    
    summer(root);
	
    return sum;
};
