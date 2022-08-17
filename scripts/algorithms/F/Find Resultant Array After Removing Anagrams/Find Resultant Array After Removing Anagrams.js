var removeAnagrams = function(words) {
    let n = words.length;
    
    for(let i=0; i<n-1; i++){
        if(isAnagram(words[i], words[i+1])){
            words.splice(i+1, 1);
            i--
            n--
        }
    }
    return words
};

function isAnagram(a, b){
    
    let freqArr = new Array(26).fill(0);
    if(a.length != b.length) return false
    
    for(let i=0; i<a.length; i++){
        let idx1 = a[i].charCodeAt(0) - "a".charCodeAt(0);
        freqArr[idx1]++;
        let idx2 = b[i].charCodeAt(0) - "a".charCodeAt(0);
        freqArr[idx2]--
    }

    
    for(let i=0; i<26; i++){
        if(freqArr[i] > 0){
            return false
        }
    }
    return true
}
