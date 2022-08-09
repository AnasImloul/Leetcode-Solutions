class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        counter = defaultdict(int)

        mostVotePersons = [0] * len(persons) # mostVotePersons[i] is the most vote person at times[i]
        largestVote = -1 # keep largest vote person index
        for i in range(len(persons)):
            counter[persons[i]] += 1
            if largestVote == -1 or counter[persons[i]] >= counter[largestVote]:
                largestVote = persons[i]
            mostVotePersons[i] = largestVote
        
        self.times = times
        self.mostVotePersons = mostVotePersons

    def q(self, t: int) -> int:
        idx = bisect_right(self.times, t) - 1 # binary search on times to find the most recent time before t
        return self.mostVotePersons[idx]
