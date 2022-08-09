/**
 * @param {string} sentence
 * @return {number}
 */
var countValidWords = function(sentence) {
    let list=sentence.split(' ')
    let filtered=list.filter(s=>{
        if(/\d/.test(s) || s=='') return false     //removes anything with numbers or is blank
        if(/^[!,.]$/.test(s)) return true          //punctuation only
        if(/^\w+[!,.]?$/.test(s)) return true      //word + optional punctuation
        if(/^\w+[-]?\w+[!,.]?$/.test(s)) return true //word + optional hypen + word + optional punctuation
        return false
    })
    
    return filtered.length
};
