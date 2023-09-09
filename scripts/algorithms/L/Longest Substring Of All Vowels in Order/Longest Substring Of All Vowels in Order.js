// Runtime: 315 ms (Top 5.8%) | Memory: 83.55 MB (Top 17.6%)

/**
 * @param {string} word
 * @return {number}
 */
var longestBeautifulSubstring = function(word) {
   
    let obj = { 'a': 1, 'e': 2, 'i': 3, 'o': 4, 'u': 5 }
    let seq = 0
    let maxstrcount = 0, strcount = ""
    for (let i = 0; i <= word.length; i++) {
        if (seq <= obj[word[i]]) {
            strcount += word[i]
            seq = obj[word[i]]
        } else {
            let set = new Set()
            for (let i = 0; i < strcount.length; i++) {
                set.add(strcount[i])
            }
            if (set.size == 5) {
                maxstrcount = Math.max(strcount.length, maxstrcount)
            }
            if (i < word.length - 1)
                i--
            strcount = ""
            seq = 0
        }
    }
    return maxstrcount
};