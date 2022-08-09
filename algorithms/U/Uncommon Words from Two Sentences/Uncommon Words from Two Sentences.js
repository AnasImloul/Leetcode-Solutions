var uncommonFromSentences = function(s1, s2) {   
    return (s1+' '+s2).split(' ').filter((el,i,arr)=>arr.indexOf(el)===arr.lastIndexOf(el))
};
