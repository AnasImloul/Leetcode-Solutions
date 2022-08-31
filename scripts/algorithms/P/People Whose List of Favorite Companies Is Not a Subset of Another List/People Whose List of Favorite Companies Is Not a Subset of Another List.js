// Runtime: 2497 ms (Top 5.55%) | Memory: 83.5 MB (Top 16.67%)
var peopleIndexes = function(favoriteCompanies) {
    let arr = favoriteCompanies
    let len = arr.length
    let ret = []
    for(let i = 0; i < len; i++) {
        let item1 = arr[i]
        let isSubset = false
        for(let j = 0; j < len; j++) {
            if(i === j) continue
            let item2 = arr[j]
            let s = new Set(item2)
            if(item1.every(a => s.has(a))) {
                isSubset = true
                break
            }
        }
        if(!isSubset) ret.push(i)
    }
    return ret
};