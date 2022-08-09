var removeOccurrences = function(s, part) {
    let n =part.length
    const reduceString = (s)=>{
        let searchPart =s.indexOf(part)
        if (searchPart<0)
            return s
        s= s.split('')
        s.splice(searchPart, n)
        s=s.join('')
        return reduceString(s)
        
    }
    return reduceString(s)
};
