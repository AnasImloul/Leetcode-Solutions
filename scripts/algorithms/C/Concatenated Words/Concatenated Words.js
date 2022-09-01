// Runtime: 578 ms (Top 25.39%) | Memory: 72.5 MB (Top 21.92%)

class Node {
    val;
    children;
    isWord = false;
    constructor(val) {
        this.val = val;
    }

}
class Trie {
    nodes = Array(26);
    addWord(w) {
        let idx = this.getIdx(w[0]);
        let node = this.nodes[idx] || new Node(w[0]);
        this.nodes[idx] = node;
        for (let i=1; i < w.length; ++i) {
            node.children = node.children || Array(26);
            idx = this.getIdx(w[i]);
            let childNode = node.children[idx] || new Node(w[i]);
            node.children[idx] = childNode;
            node = childNode;
        }

        node.isWord = true;
    }

    getExistingWords(w, start) {
        const rslt = [];
        let node = {children: this.nodes};
        for (let i=start; i < w.length; ++i) {
            node = (node.children || [])[this.getIdx(w[i])];
            if (!node) {
                break;
            }

            if (node.isWord) {
                rslt.push(i-start+1);
            }
        }

        return rslt;
    }

    getIdx(ch) {
        return ch.charCodeAt(0) - "a".charCodeAt(0);
    }
}

var findAllConcatenatedWordsInADict = function(words) {
    const rslt = [];
    words = words.sort((a,b) => a.length-b.length);
    let start = 0;
    if (words[0].length === 0) {
        ++start;
    }
    const tr = new Trie();
    for (let i = start; i < words.length; ++i) {
        if (check(words[i], 0, tr, Array(words[i].length))) {
            rslt.push(words[i]);
        }
        tr.addWord(words[i]);
    }

    return rslt;
};

function check(word, i, trie, dp) {
    if (i > word.length || dp[i] === false) {
        return false;
    }
    if (i === word.length || dp[i] === true) {
        return true;
    }
    const lens = trie.getExistingWords(word, i);
    if (!lens.length) {
        dp[i] = false;
        return false;
    }

    dp[i] = true;
    for (let l of lens) {
        if (check(word, i+l, trie, dp)) {
            return true;
        }
    }

    dp[i] = false;

    return false;
}