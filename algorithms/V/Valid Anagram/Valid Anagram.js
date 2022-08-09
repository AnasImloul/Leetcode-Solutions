var isAnagram = function(s, t) {
    if(s.length !== t.length) return false
    
    let charFreq = {}
    
    for(let char of s){
        charFreq[char] ? charFreq[char] +=1 : charFreq[char] = 1
    }
    
    for(let char of t){
        if(!(charFreq[char])) return false
        charFreq[char] -= 1
    }
    return true
};
