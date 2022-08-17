var maxScoreWords = function(words, letters, score) {
    // unique chars
    let set = new Set();
    for (let w of words)
        for (let c of w)
            set.add(c)

    // score of unique chars
    let map = new Map();
    for (let c of set)
        map.set(c, score[c.charCodeAt() - 'a'.charCodeAt()])

    // letter count
    let map_letters = new Map();
    for (let c of letters)
        map_letters.set(c, map_letters.has(c) ? map_letters.get(c) + 1 : 1);

    // score of words
    let SW = [];
    for (let w of words) {
        let s = 0;
        for (let c of w)
            s += map.get(c)
        SW.push(s)
    }

    const sortStr = (s) => s.split("").sort().join("")
    const combineStrings_fromArrayAndIndexes = (A, I) => I.reduce((s, i) => (s + A[i]), '')
    const getFreqMapFromStr = (s) => s.split("").reduce((m, c) => (m.set(c, m.has(c) ? m.get(c) + 1 : 1), m), new Map())
    const isMapSubOfAnotherMap = (m1, m2) => {
        for (let [c, count] of m1)
            if (!m2.has(c) || count > m2.get(c))
                return false
        return true
    }

    let max1 = -Infinity;
    const takeOrNot = (i, take, indexes, A, n) => {
        if (i === n) {
            if (isMapSubOfAnotherMap(
                    getFreqMapFromStr(
                        combineStrings_fromArrayAndIndexes(words, indexes)
                    ),
                    map_letters
                )) {
                let mm = indexes.reduce((sum, i) => sum + SW[i], 0)
                max1 = Math.max(max1, mm);
            }
            return
        }
        takeOrNot(i + 1, take, indexes, A, n)
        takeOrNot(i + 1, take, [...indexes, i], A, n);
    }
    takeOrNot(0, true, [], SW, SW.length);
    return max1;
};
