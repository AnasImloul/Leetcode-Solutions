var Twitter = function() {
    this.db = {}
    this.date = 0;
    this.ensureUser = function(userId) {
        if (!this.db[userId]) {
            this.db[userId] = {
                tweets: [],
                following: new Set()
            };
        }
    }
};

/** 
 * @param {number} userId 
 * @param {number} tweetId
 * @return {void}
 */
Twitter.prototype.postTweet = function(userId, tweetId) {
    this.ensureUser(userId);
    this.db[userId].tweets.push({
        id: tweetId,
        date: this.date++
    });
};

/** 
 * @param {number} userId
 * @return {number[]}
 */
Twitter.prototype.getNewsFeed = function(userId) {
    this.ensureUser(userId);
    let tweets = this.db[userId].tweets;
    this.db[userId].following.forEach(f => {
        if (this.db[f] && this.db[f].tweets) {
            tweets = [...tweets, ...this.db[f].tweets];
        }
    })
    tweets.sort((a,b) => b.date - a.date);
    if (tweets.length > 10) {
        tweets.length = 10;
    }
    return tweets.map(x => x.id);
};

/** 
 * @param {number} followerId 
 * @param {number} followeeId
 * @return {void}
 */
Twitter.prototype.follow = function(followerId, followeeId) {
    this.ensureUser(followerId);
    this.db[followerId].following.add(followeeId);
};

/** 
 * @param {number} followerId 
 * @param {number} followeeId
 * @return {void}
 */
Twitter.prototype.unfollow = function(followerId, followeeId) {
    this.db[followerId].following.delete(followeeId);
};

/** 
 * Your Twitter object will be instantiated and called as such:
 * var obj = new Twitter()
 * obj.postTweet(userId,tweetId)
 * var param_2 = obj.getNewsFeed(userId)
 * obj.follow(followerId,followeeId)
 * obj.unfollow(followerId,followeeId)
 */
