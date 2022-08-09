var minDeletionSize = function(strs) {
    const length = strs.length;
    let inOrder = true, count = 0, deleteIndex = 0;
    while(strs[0].length > 0) {
        inOrder = true;
        for(let i=0; i<length; i++) {
            if(strs[i] > strs[i+1]) {
                inOrder = false;
                for(let index = 0; index<strs[i].length;index++) {
                    if(strs[i][index] > strs[i+1][index]) {
                        deleteIndex = index;
                        break;
                    }
                }
            }
        }
        for(let i=0; i<length; i++) {
            strs[i] = strs[i].substring(0,deleteIndex) + strs[i].substring(deleteIndex+1);
        }
        if(inOrder) {
            break;
        } 
        else {
            count++;
        }
    }
    return count;    
};
