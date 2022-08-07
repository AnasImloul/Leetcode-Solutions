/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */

// Logic is same as One direction, just from both side tword mid, much faster.
// One Direction solution is here ->
// https://leetcode.com/problems/word-ladder/discuss/2372376/Easy-Fast-Simple-83.95-235-ms-50.4-MB-One-Direction

var ladderLength = function(beginWord, endWord, wordList) {
    const charMap = buildCharMap()
    const wordSet = new Set(wordList)
    if (!wordSet.has(endWord)) return 0

    let leftSet = new Set([beginWord]), rightSet = new Set([endWord]), level = 1
    
    const helper = (set1, set2) => {
        const setArr = Array.from(set1)
        for (let i = 0;  i < setArr.length; i++) {
            const word = setArr[i]
            for (let i = 0; i < word.length; i++) {
                for (const c of charMap) {
                    const newWord = word.slice(0, i) + c + word.slice(i + 1)

                    if (set2.has(newWord)) return true
                    if (wordSet.has(newWord)) { 
                        set1.add(newWord)
                        wordSet.delete(newWord)
                    }
                }
            }
            set1.delete(word)
        }
    }
    
    while (leftSet.size && rightSet.size) {
        level++
        if (helper(leftSet, rightSet)) return level
        
        level++
        if (helper(rightSet, leftSet)) return level
    }
        
    return 0
};

const buildCharMap = () => {
    const map = []
    
    for (let i = 0; i < 26; i++) {
        map.push(String.fromCharCode(i + 97))
    }
    
    return map
}
