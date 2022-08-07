
var WordDictionary = function() {
    this.aryWordList = [];
};

/** 
 * @param {string} word
 * @return {void}
 */
WordDictionary.prototype.addWord = function(word) {
    this.aryWordList.push(word);
};

/** 
 * @param {string} word
 * @return {boolean}
 */
WordDictionary.prototype.search = function(word) {
    
const isWordsMatch = (first, second) =>
  {
    if (first.length !== second.length) return false;        
      
    if (first.length == 0 && second.length == 0) return true; // Exit case for recursion

    if( first[0] === second[0] || first[0] === "." || second[0] === ".")
        return isWordsMatch(first.substring(1),
                    second.substring(1));

    return false;
}
    
    const isWordFound = () => {
        let isFound = false;
        for(var indexI=0; indexI<this.aryWordList.length; indexI++) {
            
            if(isWordsMatch(this.aryWordList[indexI], word)) { 
                isFound = true;
                break;           
            }
            
        }
        
        return isFound;
    }
    
    return word.indexOf(".") === -1 ? this.aryWordList.includes(word) : isWordFound();
};

/** 
 * Your WordDictionary object will be instantiated and called as such:
 * var obj = new WordDictionary()
 * obj.addWord(word)
 * var param_2 = obj.search(word)
 */
