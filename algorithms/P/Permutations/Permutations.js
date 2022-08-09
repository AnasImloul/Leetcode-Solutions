var permute = function(nums) {
    const output = [];
    
    const backtracking = (current, remaining) => {
        if (!remaining.length) return output.push(current);

        for (let i = 0; i < remaining.length; i++) {
            const newCurrent = [...current];
            const newRemaining = [...remaining];

            newCurrent.push(newRemaining[i]);
            newRemaining.splice(i, 1);

            backtracking(newCurrent, newRemaining);
        }
    }
    
    backtracking([], nums);

    return output;
};
