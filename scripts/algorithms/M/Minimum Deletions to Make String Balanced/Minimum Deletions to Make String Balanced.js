var minimumDeletions = function(s) {
    const dpA = [];
    let counter = 0;
    for (let i = 0; i < s.length; i++) {
        dpA[i] = counter;
        if (s[i] === 'b') {
            counter++;
        }
    }
    
    counter = 0;
    const dpB = [];
    for (let i = s.length - 1; i >= 0; i--) {
        dpB[i] = counter;
        if (s[i] === 'a') {
            counter++;
        }
    }

    let minDelete = s.length;
    for (let i = 0; i < s.length; i++) {
        minDelete = Math.min(minDelete, dpA[i] + dpB[i]);
    }
    
    return minDelete;
};
