/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function(words, maxWidth) {
    if (!words || !words.length) return;
    
    const wordRows = [];
    let wordCols = [];
    let count = 0;
    words.forEach((word, i) => {
        if ((count + word.length + wordCols.length) > maxWidth) {
            wordRows.push(wordCols);
            wordCols = [];
            count = 0;
        }
        
        wordCols.push(word);
        count += word.length;

        if (i === words.length - 1) {
            wordRows.push(wordCols);
        }        
    });
    
    return wordRows.map((rowWords, i) => justifyText(rowWords, maxWidth, i === wordRows.length - 1));
};

const justifyText = (rowWords, maxWidth, isLastLine) => {
    let spaces = maxWidth - rowWords.reduce((acc, curr) => acc + curr.length, 0);
    
    if (rowWords.length === 1) {
        return rowWords[0] + ' '.repeat(spaces);        
    }
    
    if (isLastLine) {
        spaces -= rowWords.length - 1
        return rowWords.join(' ') + ' '.repeat(spaces);        
    }
    
    let index = rowWords.length - 1;
    let justifiedWord = '';
    while (rowWords.length > 0) {
        const repeater = Math.floor(spaces / (rowWords.length - 1));
        const word = rowWords.pop();

        if (index === 0) {
            justifiedWord = word + justifiedWord;
        } else if (index === 1) {
            justifiedWord = ' '.repeat(spaces) + word + justifiedWord;
        } else {
            justifiedWord = ' '.repeat(repeater) + word + justifiedWord;
        }
        
        index--;
        spaces -= repeater;
    }

    return justifiedWord;
}
