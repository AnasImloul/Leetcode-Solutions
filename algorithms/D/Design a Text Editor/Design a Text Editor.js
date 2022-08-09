

var TextEditor = function() {
    this.forward = [];
    this.backward = [];
};

/** 
 * @param {string} text
 * @return {void}
 */
TextEditor.prototype.addText = function(text) {
    for (let letter of text) {
        this.forward.push(letter);
    }
};

/** 
 * @param {number} k
 * @return {number}
 */
TextEditor.prototype.deleteText = function(k) {
    let deleted = 0;
    while (this.forward.length && deleted < k) {
        this.forward.pop();
        deleted++;
    }
    return deleted;
};

/** 
 * @param {number} k
 * @return {string}
 */
TextEditor.prototype.cursorLeft = function(k) {
    let moved = 0;
    while (this.forward.length && moved < k) {
        this.backward.push(this.forward.pop());
        moved++;
    }
    return toTheLeft(this.forward);
};

/** 
 * @param {number} k
 * @return {string}
 */
TextEditor.prototype.cursorRight = function(k) {
    let moved = 0;
    while (moved < k && this.backward.length) {
        this.forward.push(this.backward.pop());
        moved++;
    }
    return toTheLeft(this.forward);
};


function toTheLeft (arr) {
    let letters = [];
    for (let i = Math.max(0, arr.length - 10); i < arr.length; i++) {
        letters.push(arr[i]);
    }
    let res = letters.join("");
    return res; 
}

