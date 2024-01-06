// Runtime: 85 ms (Top 92.31%) | Memory: 47.10 MB (Top 100.0%)

var canReorderDoubled = function(arr) {
    const hashMap = arr.reduce((map, num) => {
        const count = map.get(num) ?? 0;
        return map.set(num, count + 1);
    }, new Map());

    const nums = [...hashMap.keys()].sort((a, b) => {
        return a < 0 && b < 0 ? b - a : a - b;
    });

    for (const num of nums) {
        const count = hashMap.get(num);
        const pairsCount = hashMap.get(num * 2);
        if (count > pairsCount) return false;
        if (count > 0 && pairsCount === undefined) return false;
    
        hashMap.set(num * 2, pairsCount - count);
    }
    return true;
};
