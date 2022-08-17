var mostPoints = function(questions) {
    let totalQuestions = questions.length;
    
    let map = new Map();
    
    const helper = (index) => {
        if(map.has(index))
            return map.get(index);
        
        if(index >= totalQuestions) {
            return 0;
        }  
        
        let solve = questions[index][0] + helper(index + questions[index][1] + 1);
        
        let skip = helper(index + 1);
        
        let res = Math.max(solve, skip);
        
        map.set(index, res);
        
        return res;
    }
    
    return helper(0);
	
