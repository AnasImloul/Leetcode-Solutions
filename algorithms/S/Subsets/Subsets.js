var subsets = function(nums) {
    
    const res = [];
    
    const dfs = (i, slate) => {
        
        if(i == nums.length){
            
            res.push(slate.slice());
            
            return;
            
        }
        
		// take the current number into the subset.
        slate.push(nums[i]);
        dfs(i + 1, slate);
        slate.pop();
        
		// ignore the current number.
        dfs(i + 1, slate);  
        
    }
    
    dfs(0, []);
    
    return res;
    
};
