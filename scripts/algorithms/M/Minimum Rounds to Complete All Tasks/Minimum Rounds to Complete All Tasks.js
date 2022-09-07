// Runtime: 171 ms (Top 86.61%) | Memory: 55.3 MB (Top 97.32%)
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