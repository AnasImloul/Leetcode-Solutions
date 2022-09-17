// Runtime: 108 ms (Top 32.13%) | Memory: 44.5 MB (Top 16.74%)
var canBeTypedWords = function(text, brokenLetters) {
    let regexp="["+brokenLetters+"]\+"
    let word=text.split(" "), count=0;
    for(let i=0; i<word.length; i++){
        let work=true;
        // if matches, means word[i] contains malfunction letters.
        if(word[i].match(regexp)){work=false};
        if(work){count++};
    }
    return count;
};