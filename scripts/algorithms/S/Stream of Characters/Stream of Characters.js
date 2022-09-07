// Runtime: 727 ms (Top 21.67%) | Memory: 101.6 MB (Top 6.67%)
var StreamChecker = function(words) {
    function Trie() {
        this.suffixLink = null; //this is where it will fallback to when a letter can't be matched
        this.id = -1; //this id will be 0 or greater if it matches a word
        this.next = new Map(); //map of <char, Trie*>
    }
    this.root = new Trie();
    this.uniqueIds = 0; //used to count all the unique words discovered and as part of the Trie id system

    //standard trie traversal but keeping track of new words via id system
    for (const word of words) {
        let ptr = this.root;
        for (const c of word) {
            if (!ptr.next.has(c)) {
                ptr.next.set(c, new Trie());
            }
            ptr = ptr.next.get(c);
        }
        if (ptr.id === -1) {
            ptr.id = this.uniqueIds++;
        }
    }

    //BFS traversal to build the automaton
    const q = [];
    for (const [c, node] of this.root.next) {
        //all first level children should point back to the root when a match to a character fails
        node.suffixLink = this.root;
        q.push(node);
    }

    while (q.length) {
        const curr = q.shift();
        for (const [c, node] of curr.next) {

            let ptr = curr.suffixLink;
            while (ptr !== this.root && !ptr.next.has(c)) {
                ptr = ptr.suffixLink;
            }
            //find the next suffixLink if it matches the current character or fallback to the root
            node.suffixLink = ptr.next.get(c) ?? this.root;

            //if the current suffixLink happens to also be a word we should store its id to make it quick to find
            if (node.suffixLink.id !== -1) {
                node.id = node.suffixLink.id;
            }
            q.push(node);
        }
    }
    //the query ptr will now track every new streamed character and use it to match
    this.queryPtr = this.root;
};

StreamChecker.prototype.query = function(letter) {
    //the query ptr will now track every new streamed character and can be used to quickly find words
    while (this.queryPtr !== this.root && !this.queryPtr.next.has(letter)) {
        this.queryPtr = this.queryPtr.suffixLink;
    }
    this.queryPtr = this.queryPtr.next.get(letter) ?? this.root;
    //if any word is found it will have an id that isn't -1
    return this.queryPtr.id !== -1;
};