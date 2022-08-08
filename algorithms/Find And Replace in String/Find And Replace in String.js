var findReplaceString = function(s, indices, sources, targets) {
    let res = s.split(''); 

    for(let i=0; i<indices.length; i++) { 
        let index = indices[i]; 
        let str = sources[i]; 
        
        if(s.slice(index, index + str.length) == str) {
            res[index] = targets[i]; 
            for(let j = 1; j < str.length; j++) { 
                res[index+=1] = ""; 
            }
        }
    }

    return res.join('');
};
