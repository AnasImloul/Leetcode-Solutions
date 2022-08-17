var minimumRounds = function(tasks) {
    const hash = {};
    let minRounds = 0;
    
    for (const task of tasks) {
        hash[task] = hash[task] + 1 || 1;
    }
    
    for (const count of Object.values(hash)) {
        if (count < 2) return -1;
        minRounds += Math.ceil(count / 3);
    }
    
    return minRounds;
};
