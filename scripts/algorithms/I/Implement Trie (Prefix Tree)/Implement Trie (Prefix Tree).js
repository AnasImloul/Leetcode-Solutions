// Runtime: 278 ms (Top 63.18%) | Memory: 65.8 MB (Top 36.92%)

var Trie = function() {
    this.children = {};
    this.word = false;
};

/**
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    if (!word) {
        this.word = true;
        return null;
    }
    let head = word[0];
    let tail = word.substring(1);

    if (!this.children[head]) {
        this.children[head] = new Trie();
    }
    this.children[head].insert(tail);
};

/**
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype._search = function(word, method) {
    if (!word) {
        if (method === 'search') {
            return this.word;
        } else {
            return true;
        }
    }
    let head = word[0];
    let tail = word.substring(1);

    if (!this.children[head]) {
        return false;
    }

    return this.children[head][method](tail);
};

/**
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    return this._search(word, 'search');
};

/**
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    return this._search(prefix, 'startsWith');
};

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */