// Runtime: 74 ms (Top 79.90%) | Memory: 44.6 MB (Top 9.41%)
/**
 * @param {string[]} words
 * @param {string} order
 * @return {boolean}
 */
var isAlienSorted = function(words, order) {
    let map = {}
    for(let i = 0; i < 26; i++){
        map[order[i]] = i
    }
    for(let i = 0; i < words.length - 1; i++){
        for(let j = 0; j < words[i].length; j++){
            if(j === words[i+1].length) return false
            if(words[i][j] !== words[i+1][j]){
                if(map[words[i+1][j]] < map[words[i][j]]) return false
                break
            }
        }
    }
    return true
};