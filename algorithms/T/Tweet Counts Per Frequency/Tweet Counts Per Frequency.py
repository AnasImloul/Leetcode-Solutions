import bisect
class TweetCounts:

    def __init__(self):
        self.tweets = {}
        

    def recordTweet(self, tweetName: str, time: int) -> None:
        if not tweetName in self.tweets:
            self.tweets[tweetName] = []
        index = bisect.bisect_left(self.tweets[tweetName], time)
        self.tweets[tweetName].insert(index, time)
        
    
    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        
        def find(step):
            nonlocal tweet
            result = []
            for i in range(startTime, endTime+1, step):
                result.append(bisect.bisect_right(tweet, min(endTime, i + step - 1)) - bisect.bisect_left(tweet, i))
            return result
                
                
        tweet = self.tweets[tweetName]
        if freq == "minute":
            return find(60)
        elif freq == "hour":
            return find(3600)
        else:
            return find(86400)