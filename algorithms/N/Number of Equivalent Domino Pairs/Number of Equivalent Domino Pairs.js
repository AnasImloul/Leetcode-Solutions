var numEquivDominoPairs = function(dominoes) {
    let map = {};
    let count = 0;
    for (let [a, b] of dominoes) {
        if (b > a) {
            [a, b] = [b, a];
        }
        let key = `${a}-${b}`;
        if (map.hasOwnProperty(key)) {
            map[key]++;
            count += map[key];
        } else {
            map[key] = 0;
        }
    }
    return count;
};
