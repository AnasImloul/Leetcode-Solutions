// Runtime: 48 ms (Top 79.27%) | Memory: 49.00 MB (Top 5.82%)

var Twitter = function() {
    this.users = new Map();
    this.tweets = [];
};

Twitter.prototype.postTweet = function(userId, tweetId) {
    if(!this.users.has(userId)) this.users.set(userId, new Set());
    this.tweets.push({userId, tweetId})
};

Twitter.prototype.getNewsFeed = function(userId) {
    let user = this.users.get(userId);
    let recentTweets = [];
    for(let i = this.tweets.length - 1; i >= 0 && recentTweets.length < 10; i--){
        if(user.has(this.tweets[i].userId) || this.tweets[i].userId === userId){
            recentTweets.push(this.tweets[i].tweetId);
        }
    }
  return recentTweets;
};

Twitter.prototype.follow = function(followerId, followeeId) {
    let user = this.users.get(followerId) || new Set();
    user.add(followeeId);
    this.users.set(followerId, user);
};

Twitter.prototype.unfollow = function(followerId, followeeId) {
    this.users.get(followerId)?.delete(followeeId);
};
