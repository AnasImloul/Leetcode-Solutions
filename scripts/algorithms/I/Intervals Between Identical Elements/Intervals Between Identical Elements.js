// Runtime: 295 ms (Top 84.0%) | Memory: 107.90 MB (Top 94.0%)

var getDistances = function(arr) {
    const map = new Map();
    const result = new Array(arr.length).fill(0);

    for (let i = 0; i < arr.length; i++) {
        const num = arr[i];
        const val = map.get(num) || {
            count: 0,
            sum: 0
        };
        result[i] += (val.count * i) - val.sum;
        val.sum += i;
        val.count++;
        map.set(num, val);
    }
    map.clear();

    for (let i = arr.length - 1; i >= 0; i--) {
        const num = arr[i];
        const val = map.get(num) || {
            count: 0,
            sum: 0
        };
        result[i] += val.sum - (val.count * i);
        val.sum += i;
        val.count++;
        map.set(num, val);
    }

    return result;
};
