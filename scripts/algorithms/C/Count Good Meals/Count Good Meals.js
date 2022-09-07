// Runtime: 216 ms (Top 89.74%) | Memory: 61.6 MB (Top 38.46%)
var countPairs = function(deliciousness) {
    const n = deliciousness.length;
    const MOD = 1e9 + 7;

    const map = new Map();

    for (const num of deliciousness) {
        if (!map.has(num)) map.set(num, 0);
        map.set(num, map.get(num) + 1);
    }

    let max = 2**21;
    let res = 0;

    for (const [num, count] of map) {

        let two = 1;

        while (two <= max) {
            const diff = two - num;

            if (diff >= 0 && map.has(diff)) {

                const otherCount = map.get(diff);

                if (num != diff) res += (count * otherCount);
                else res += (count * (count - 1) / 2);
            }

            two <<= 1;
        }

        map.delete(num);
    }

    return res % MOD;
};