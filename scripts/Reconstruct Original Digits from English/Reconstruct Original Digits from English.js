/**
 * @param {string} s
 * @return {string}
 */
 
var originalDigits = function(s) {
    const numberToWord = {
        0: 'zero',
        1: 'one',
        2: 'two',
        3: 'three',
        4: 'four',
        5: 'five',
        6: 'six',
        7: 'seven',
        8: 'eight',
        9: 'nine'
    }
    
    const letterToDigits = {}
    
    for(const key in numberToWord) {
        const currWord = numberToWord[key]
        
        for(const letter of currWord) {
            if(!(letter in letterToDigits)) letterToDigits[letter] = new Set()
            letterToDigits[letter].add(key)
        }
    }
    
    const inputFreqs = {}
    
    for(let i = 0; i < s.length; i++) {
        const currChar = s[i]
        
        if(!(currChar in inputFreqs)) inputFreqs[currChar] = 0
        inputFreqs[currChar]++
    }
    
    const letters = Object.keys(inputFreqs)
    
    const res = dfs(letters[0])
    
    return [...res].sort().join('')
    
    function dfs(currLetter) {
        if(!isValid(inputFreqs)) return null
        if(getTotalRemaining(inputFreqs) === 0) return []
        const possibleDigits = letterToDigits[currLetter]
        
        for(const digit of [...possibleDigits]) {
            const wordRepresentation = numberToWord[digit]
            
            subtract(wordRepresentation)
            
            if(!isValid(inputFreqs)) {
                addBack(wordRepresentation)
                continue
            }
            
            const nextLetter = getNext(inputFreqs)
            const nextDigits = dfs(nextLetter)
            
            if(nextDigits !== null) return [digit] + nextDigits
            
            addBack(wordRepresentation)
        }
        
        return null
    }
    
    function isValid(inputFreqs) {
        for(const key in inputFreqs) {
            const count = inputFreqs[key]
            
            if(count < 0) return false
        }
        
        return true
    }
    
    function getTotalRemaining(inputFreqs) {
        let sum = 0
        
        for(const key in inputFreqs) {
            const count = inputFreqs[key]
            
            sum += count
        }
        
        
        return sum
    }
    
    function subtract(word) {
        for(const char of word) {
            if(!(char in inputFreqs)) inputFreqs[char] = 0
            inputFreqs[char]--
        }
    }
    
    
    function addBack(word) {
        for(const char of word) {
            inputFreqs[char]++
        }
    }
    
    function getNext(inputFreqs) {
        for(const key in inputFreqs) {
            const count = inputFreqs[key]
            
            if(count > 0) return key
        }
        
        return null
    }
};
