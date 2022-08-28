// Runtime: 111 ms (Top 17.77%) | Memory: 42.1 MB (Top 85.95%)
var uncommonFromSentences = function(s1, s2) {
    return (s1+' '+s2).split(' ').filter((el,i,arr)=>arr.indexOf(el)===arr.lastIndexOf(el))
};