var isPrefixOfWord = function(sentence, searchWord) {
    let arr = sentence.split(' ');
    
    for (let i = 0; i < arr.length; i++) {
        let word = arr[i];
        
        if (word.startsWith(searchWord)) return i + 1;
    }
    
    return -1;
};
