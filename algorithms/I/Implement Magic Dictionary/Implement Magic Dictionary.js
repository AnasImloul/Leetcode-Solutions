var MagicDictionary = function() {
    this.trie = {};
};

MagicDictionary.prototype.buildDict = function(dictionary) {
    for(let word of dictionary) {
        let curr = this.trie;
        for(let c of word) {
            if(!curr[c]) curr[c] = {};
            curr = curr[c];
        }
        curr['end'] = true;
    }
};

MagicDictionary.prototype.search = function(searchWord) {
    const len = searchWord.length;
    const searchHelper = (idx = 0, mismatch = 1, curr = this.trie) => {
        for(let i = idx; i < len; i++) {
            const c = searchWord[i];
            
            if(!curr[c]) {
                if(mismatch == 0) return false;
                
                for(let possibleChar in curr) {
                    if(searchHelper(i + 1, mismatch - 1, curr[possibleChar])) {
                        return true;
                    }
                }
                return false;
            } else {
                for(let possibleChar in curr) {
                    if(c == possibleChar) continue;
                    if(searchHelper(i + 1, mismatch - 1, curr[possibleChar])) {
                        return true;
                    }
                }
            }
            curr = curr[c];
        }
        return Boolean(curr['end'] && mismatch == 0);
    }
    return searchHelper();
};
