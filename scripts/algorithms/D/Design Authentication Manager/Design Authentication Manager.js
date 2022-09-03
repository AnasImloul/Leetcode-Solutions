// Runtime: 360 ms (Top 51.28%) | Memory: 62 MB (Top 5.13%)
/**
 * @param {number} timeToLive
 */
var AuthenticationManager = function(timeToLive) {
    this.timeToLive=timeToLive;
    this.tokens=new Map();
};

/**
 * @param {string} tokenId
 * @param {number} currentTime
 * @return {void}
 */
AuthenticationManager.prototype.generate = function(tokenId, currentTime) {
    if(!this.tokens.has(tokenId)){
        let tokenInfo={
            tokenId:tokenId,
            expiresAt:currentTime+this.timeToLive
        }
        this.tokens.set(tokenId,tokenInfo);
    }
};

/**
 * @param {string} tokenId
 * @param {number} currentTime
 * @return {void}
 */
AuthenticationManager.prototype.renew = function(tokenId, currentTime) {
    if(!this.tokens.has(tokenId)) return;

    let token=this.tokens.get(tokenId);
    if(token.expiresAt>currentTime){
        this.tokens.set(tokenId,{...token,expiresAt:currentTime+this.timeToLive})
    }else{
        this.tokens.delete(tokenId);
    }
};

/**
 * @param {number} currentTime
 * @return {number}
 */
AuthenticationManager.prototype.countUnexpiredTokens = function(currentTime) {
    let activeTokensCount=0;
    for(let [key,token] of this.tokens.entries()){
        if(token.expiresAt>currentTime) activeTokensCount++;
    }
    return activeTokensCount;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * var obj = new AuthenticationManager(timeToLive)
 * obj.generate(tokenId,currentTime)
 * obj.renew(tokenId,currentTime)
 * var param_3 = obj.countUnexpiredTokens(currentTime)
 */