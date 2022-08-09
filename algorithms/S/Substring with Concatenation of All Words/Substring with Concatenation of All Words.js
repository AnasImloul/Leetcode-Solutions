var findSubstring = function(s, words) {
    
    let res = [];

    let wordLength = words[0].length;
    let wordCount = words.length;
    let len = wordCount * wordLength; //Length of sliding window
    
    let map = {}
    
    for (let word of words) map[word] = map[word] + 1 || 1; //Hash word freq

  	for (let i = 0; i < s.length - len + 1; i++) {
            let sub = s.slice(i, i + len); //Generate substring of sliding window length
            if (isConcat(sub, map, wordLength)) res.push(i)
        }
    
    return res;
};

function isConcat(sub,map,wordLength){
    
    let seen = {};
    for (let i = 0; i < sub.length; i+=wordLength) {
        let word = sub.slice(i,i + wordLength);
        seen[word] = seen[word] + 1 || 1
    }
    
    for(let key in map){
        if(map[key] !== seen[key]) return false; //Word freq must match between map and seen
    }
    return true;
}```