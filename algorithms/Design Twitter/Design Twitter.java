class Twitter {
    Map<Integer, List<int[]>> userToTweetMap;
    Map<Integer, Set<Integer>> followMap;
    // Map<Integer, Set<Integer>> followersMap; // not needed for now
    int time = 0;
    
    int RETURN_TWEET_LIMIT = 10;

    public Twitter() {
        userToTweetMap = new HashMap<>();
		followMap = new HashMap<>();
    }
    
    // O(1)
    public void postTweet(int userId, int tweetId) {
        time++;
		userToTweetMap.putIfAbsent(userId, new ArrayList<>());
		userToTweetMap.get(userId).add(new int[]{time, tweetId});

		followMap.computeIfAbsent(userId, a -> new HashSet<>()).add(userId);
    }
    
    // O(N): N -> number of followers
    public List<Integer> getNewsFeed(int userId) {
        if (!followMap.containsKey(userId)) return new ArrayList<>();
		Set<Integer> followedUsers = followMap.get(userId);

		PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
		for (Integer user : followedUsers) {
			List<int[]> tweets = userToTweetMap.get(user);
            if(tweets == null) continue;
			int size = tweets.size();

			int start = Math.max(size - RETURN_TWEET_LIMIT, 0);
			while (start < size) {
				pq.add(tweets.get(start++));
				if (pq.size() > RETURN_TWEET_LIMIT) pq.remove();
			}
		}

		List<Integer> res = new ArrayList<>();
		while (!pq.isEmpty()) res.add(pq.poll()[1]);
        Collections.reverse(res);
        
		return res;
    }
    
    // O(1)
    public void follow(int followerId, int followeeId) {
        followMap.computeIfAbsent(followerId, a -> new HashSet<>()).add(followeeId);
    }
    
    // O(1)
    public void unfollow(int followerId, int followeeId) {
        if (followMap.containsKey(followerId) && followMap.get(followeeId).contains(followeeId))
			followMap.get(followerId).remove(followeeId);
    }
}
