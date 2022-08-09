var Encrypter = function(keys, values, dictionary) {
    this.encryptMap = new Map();
    for (let i = 0; i < keys.length; i++) {
        this.encryptMap.set(keys[i], values[i]);
    }
    this.dict = new Set(dictionary);
    // Encypt the values in dict for easy comparison later
    this.encryptedVals = [];
    for (let word of this.dict) {
        this.encryptedVals.push(this.encrypt(word));
    }
};
Encrypter.prototype.encrypt = function(word1) {
    let encrypted = '';
    for (let char of word1) {
        encrypted += this.encryptMap.get(char);
    }
    return encrypted;
};
Encrypter.prototype.decrypt = function(word2) {
    return this.encryptedVals.filter(x => x === word2).length;
};
