var wordPattern = function(pattern, s) {
    let wordArray = s.split(" ");
    if(wordArray.length !== pattern.length) return false;
    
    let hm = {};
    let hs = new Set();
    
    for(let index in pattern) {
        let word = wordArray[index];
        let char = pattern[index];
        
        if(hm[char] !== undefined) {
            if(hm[char] !== word) return false;    
        } else {
            if(hs.has(word)) return false; // Duplicate Occurence of word on first occurrence of a char
            hm[char] = word;
            hs.add(word);
        }
    }
    
    return true;
}
