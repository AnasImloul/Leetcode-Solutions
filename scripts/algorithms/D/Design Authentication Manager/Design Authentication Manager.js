// Runtime: 211 ms (Top 9.0%) | Memory: 51.68 MB (Top 72.7%)

// O(n)
var AuthenticationManager = function(timeToLive) {
    this.ttl = timeToLive;
    this.map = {};
};
AuthenticationManager.prototype.generate = function(tokenId, currentTime) {
    this.map[tokenId] = currentTime + this.ttl;
};
AuthenticationManager.prototype.renew = function(tokenId, currentTime) {
    let curr = this.map[tokenId];
    if (curr > currentTime) {
        this.generate(tokenId, currentTime);
    }
};
AuthenticationManager.prototype.countUnexpiredTokens = function(currentTime) {
    return Object.keys(this.map).filter(key => this.map[key] > currentTime).length;
};