// Runtime: 120 ms (Top 38.46%) | Memory: 44.7 MB (Top 61.54%)
var flipgame = function(fronts, backs) {
    const MAX = Number.MAX_SAFE_INTEGER;
    const n = fronts.length;
    const set = new Set();

    let min = MAX;

    for (let i = 0; i < n; i++) {
        const front = fronts[i];
        const back = backs[i];

        if (front === back) {
            set.add(front);
        }
    }

    for (let i = 0; i < n; i++) {
        const front = fronts[i];
        const back = backs[i];

        if (front === back) continue;

        if (!set.has(front)) min = Math.min(front, min);
        if (!set.has(back)) min = Math.min(back, min);
    }

    return min === MAX ? 0 : min;
};