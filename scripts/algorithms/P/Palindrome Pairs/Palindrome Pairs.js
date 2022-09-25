// Runtime: 1780 ms (Top 68.62%) | Memory: 64.1 MB (Top 88.11%)
var palindromePairs = function(words) {
    let wmap = new Map(), ans = []
    for (let i = 0; i < words.length; i++)
        wmap.set(words[i], i)
    for (let i = 0; i < words.length; i++) {
        if (words[i] === "") {
            for (let j = 0; j < words.length; j++)
                if (isPal(words[j]) && j !== i)
                    ans.push([i, j], [j, i])
            continue
        }
        let bw = words[i].split("").reverse().join("")
        let res = wmap.get(bw)
        if (res !== undefined && res !== i)
            ans.push([i, res])
        for (let j = 1; j < bw.length; j++) {
            if (isPal(bw, 0, j - 1)) {
                let res = wmap.get(bw.slice(j))
                if (res !== undefined)
                    ans.push([i, res])
            }
            if (isPal(bw, j)) {
                let res = wmap.get(bw.slice(0,j))
                if (res !== undefined)
                    ans.push([res, i])
            }
        }
    }
    return ans
};

const isPal = (word, i=0, j=word.length-1) => {
    while (i < j)
        if (word[i++] !== word[j--]) return false
    return true
}