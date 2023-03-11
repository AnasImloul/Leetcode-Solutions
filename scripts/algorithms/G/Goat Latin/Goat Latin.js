/**
 * @param {string} S
 * @return {string}
 */
var toGoatLatin = function(S) {
    let re = /[aeiou]/gi
    let word = S.split(' ')
    let add = 0
    let arr = []
    
    for(let i= 0; i < word.length; i++) {
        if(!word[i].substring(0,1).match(re)) {
            arr = word[i].split('')
            let letter = arr.shift()
            arr.push(letter)
            word[i] = arr.join('')
        }
        
        // have to append 'ma' regardless if it starts with a vowel
        word[i] += 'ma'
        
        // append 'a' number of times as the index + 1
        add = i+1
        while(add >0) {
            word[i] += 'a'
            add--
        }
    }
    
    return word.join(' ')
};