var findNumOfValidWords = function(words, puzzles) {
	// Form map of word's bitmasks
    const wordsMaskMap = words.reduce((map, word) => addToMap(map, getMask(word)), new Map())

    return puzzles.map(puzzle => {
        const pMask = getMask(puzzle)
        const pFirstMask = getFirstMask(puzzle)
        let count = 0
        
		// Verify each bitmask against a given puzzle
        for (let wMask of wordsMaskMap.keys()) {
            if((wMask & pFirstMask) && (!((wMask | pMask) ^ pMask))) {
                count += wordsMaskMap.get(wMask)
            }
        }
        return count
    })
}

// Transform a char into a bit index
var getBit = (char) => 1 << char.charCodeAt(0) - 'a'.charCodeAt(0)

// Transform a word into a bitmask
var getMask = (word) => word.split('').reduce((acc, c) => acc | getBit(c), 0)

// Get a bitmask for the first letter of a word
var getFirstMask = (word) => getBit(word[0])

// Helper function to count hashes in a Map object 
var addToMap = (map, val) => map.has(val) ? map.set(val, map.get(val) + 1) : map.set(val, 1)