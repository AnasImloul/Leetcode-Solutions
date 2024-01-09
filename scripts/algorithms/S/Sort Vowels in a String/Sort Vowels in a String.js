// Runtime: 128 ms (Top 96.83%) | Memory: 54.40 MB (Top 95.15%)

var sortVowels = function(s) {
    const vowels = "AEIOUaeiou"
    const count = new Array(vowels.length).fill(0)
    for (let char of s) {
        const index = vowels.indexOf(char)
        if (index !== -1) {
            count[index]++
        }
    }
    let str = ""
    let curr = 0
    for (let char of s) {
        if (vowels.includes(char)) {
            while (count[curr] === 0) {
                curr++
            }

            str += vowels[curr]
            count[curr]--
        } else {
            str += char
        }
    }
    return str
};
