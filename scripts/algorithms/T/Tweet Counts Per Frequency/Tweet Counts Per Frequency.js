// Runtime: 342 ms (Top 68.75%) | Memory: 56.4 MB (Top 87.50%)
var TweetCounts = function() {
    this.map = new Map();
};

TweetCounts.prototype.recordTweet = function(tweetName, time) {
    if (!this.map.has(tweetName)) this.map.set(tweetName, []);
    this.map.get(tweetName).push(time);
};

TweetCounts.prototype.getTweetCountsPerFrequency = function(freq, tweetName, startTime, endTime) {
    if (!this.map.has(tweetName)) return [];

    const tweets = this.map.get(tweetName);
    const buckets = createBuckets(freq, startTime, endTime);

    for (let i = 0; i < tweets.length; i++) {
        const tweetTime = tweets[i];

        let left = 0;
        let right = buckets.length - 1;

        while (left <= right) {
            const mid = (left + right) >> 1;
            const [startTime, endTime, count] = buckets[mid];

            if (startTime <= tweetTime && tweetTime <= endTime) {
                buckets[mid][2] = count + 1;
                break;
            }

            if (endTime < tweetTime) left = mid + 1;
            else right = mid - 1;
        }
    }

    const res = [];

    for (let i = 0; i < buckets.length; i++) {
        res.push(buckets[i][2]);
    }

    return res;

    function createBuckets(freq, startTime, endTime) {
        const chunks = { "minute": 60, "hour": 3600, "day": 86400 };
        const buckets = [];

        let start = startTime;

        while (start <= endTime) {
            const end = Math.min(start + chunks[freq] - 1, endTime);
            buckets.push([start, end, 0])
            start = end + 1;
        }

        return buckets;
    }
};