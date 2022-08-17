var mostVisited = function(n, rounds) {
    const first = rounds[0];
    const last = rounds[rounds.length - 1];
   
    const result = [];
   
    if (first <= last) {
        for (let i = last; i >= first; i--) result.unshift(i)
    } else {
        for (let i = 1; i <= last; i++) result.push(i);
        for (let i = first; i <= n; i++) result.push(i);
    }
   
    return result;
};
