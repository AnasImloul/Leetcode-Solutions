// Runtime: 175 ms (Top 77.53%) | Memory: 49.4 MB (Top 96.25%)
var countCharacters = function(words, chars) {
    let arr = [];
    loop1: for(word of words){
        let characters = chars;
        loop2: for( char of word ){
            if(characters.indexOf(char) === -1){
                continue loop1;
            }
            characters = characters.replace(char,'');
        }
        arr.push(word);
    }
    return arr.join('').length;
};