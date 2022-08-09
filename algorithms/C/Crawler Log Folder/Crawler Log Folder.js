var minOperations = function(logs) {
    let count = 0;
    for(i=0;i<logs.length;i++){
        if(logs[i] === '../') {
            if(count > 0)  count = count - 1;
            continue
        }
        if(logs[i] === './') continue;
        else count = count + 1;
    }
    return count
};
