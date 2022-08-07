class Twitter:

    def __init__(self):
        self.tweets = []
        self.friends = defaultdict(list)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweets.append([userId, tweetId])   

    def getNewsFeed(self, userId: int) -> List[int]:
        try:
            tweets = [x[1] for x in self.tweets if x[0] in [userId]+self.friends[userId]]
            return list(reversed(tweets))[:10]
        except:
            return 

    def follow(self, followerId: int, followeeId: int) -> None:
        self.friends[followerId].append(followeeId)  

    def unfollow(self, followerId: int, followeeId: int) -> None:
        try:
            self.friends[followerId].remove(followeeId)
        except:
            pass
