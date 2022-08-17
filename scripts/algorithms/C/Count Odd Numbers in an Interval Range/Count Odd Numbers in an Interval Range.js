var countOdds = function(low, high) {
    let total = 0;
    for (let i = low; i <= high; i++) {
        if (i % 2 !== 0) {
            total++;
        }
    }
    return total;
};
