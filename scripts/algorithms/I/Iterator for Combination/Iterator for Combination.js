// Runtime: 91 ms (Top 48.4%) | Memory: 50.62 MB (Top 48.4%)

var CombinationIterator = function(characters, combinationLength) {
    this.stack = Array.from({ length: combinationLength }, (_, i) => i);
    this.combinationLength = combinationLength;
    this.characters = characters;
};

CombinationIterator.prototype.next = function() {
    const word = this.stack.map((i) => this.characters[i]).join("");

    for (let lastIndex = this.characters.length - 1; this.stack.at(-1) == lastIndex; )
        lastIndex = this.stack.pop() - 1;

    if (this.stack.length > 0)
        for (let i = this.stack.pop() + 1; this.stack.length < this.combinationLength; i++)
            this.stack.push(i);
    
    return word;
};

CombinationIterator.prototype.hasNext = function() {
    return this.stack.length > 0;
};
