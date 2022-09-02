// Runtime: 135 ms (Top 21.74%) | Memory: 46.8 MB (Top 86.96%)
var numSpecialEquivGroups = function(words) {
    const set = new Set()
    const a = 'a'.charCodeAt(0)
    const alphaCounter = new Array(26).fill(0)
    for (const word of words) {
        const [even, odd] = [[...alphaCounter], [...alphaCounter]]
        word.split('').forEach((l,i) => {
            l = l.charCodeAt(0) - a
            if (i%2) odd[l]++
            else even[l]++
        })
        const hashkey = even.join('') + odd.join('')
        set.add(hashkey)
    }
    return set.size
};