class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        e = defaultdict(list)
        m = len(beginWord)
        for word in wordList + [beginWord]:
            for i in range(m):
                w = word[:i] + "*" + word[i + 1:]
                e[w].append(word)
        q = deque([beginWord])
        used = set([beginWord])
        d = 0
        while q:
            d += 1
            for _ in range(len(q)):
                word = q.popleft()
                for i in range(m):
                    w = word[:i] + "*" + word[i + 1:]
                    if w in e:
                        for v in e[w]:
                            if v == endWord:
                                return d + 1
                            if v not in used:
                                q.append(v)
                                used.add(v)
                        e.pop(w)
        return 0
