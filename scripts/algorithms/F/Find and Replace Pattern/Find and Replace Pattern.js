// Runtime: 41 ms (Top 98.6%) | Memory: 42.10 MB (Top 94.41%)

var findAndReplacePattern = function(words, pattern) {
    let ans = [], codex = new Map()
    const translate = char => {
        if (!codex.has(char))
            codex.set(char, String.fromCharCode(97 + codex.size))
        return codex.get(char)
    }
    const compare = word => {
        codex.clear()
        for (let i = 0; i < word.length; i++)
            if (translate(word[i]) !== cipher[i])
                return
        ans.push(word)
    }
    let cipher = new Array(pattern.length)
    for (let i = 0; i < pattern.length; i++)
        cipher[i] = translate(pattern.charAt(i))
    words.forEach(compare)
    return ans
};
