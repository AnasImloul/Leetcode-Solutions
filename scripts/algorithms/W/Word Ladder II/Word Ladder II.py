# Runtime: 80 ms (Top 72.71%) | Memory: 14.5 MB (Top 54.17%)
class Solution:

    WILDCARD = "."

    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        """
        Given a wordlist, we perform BFS traversal to generate a word tree where
        every node points to its parent node.

        Then we perform a DFS traversal on this tree starting at the endWord.
        """
        if endWord not in wordList:
            # end word is unreachable
            return []

        # first generate a word tree from the wordlist
        word_tree = self.getWordTree(beginWord, endWord, wordList)

        # then generate a word ladder from the word tree
        return self.getLadders(beginWord, endWord, word_tree)

    def getWordTree(self,
                    beginWord: str,
                    endWord: str,
                    wordList: List[str]) -> Dict[str, List[str]]:
        """
        BFS traversal from begin word until end word is encountered.

        This functions constructs a tree in reverse, starting at the endWord.
        """
        # Build an adjacency list using patterns as keys
        # For example: ".it" -> ("hit"), "h.t" -> ("hit"), "hi." -> ("hit")
        adjacency_list = defaultdict(list)
        for word in wordList:
            for i in range(len(word)):
                pattern = word[:i] + Solution.WILDCARD + word[i+1:]
                adjacency_list[pattern].append(word)

        # Holds the tree of words in reverse order
        # The key is an encountered word.
        # The value is a list of preceding words.
        # For example, we got to beginWord from no other nodes.
        # {a: [b,c]} means we got to "a" from "b" and "c"
        visited_tree = {beginWord: []}

        # start off the traversal without finding the word
        found = False

        q = deque([beginWord])
        while q and not found:
            n = len(q)

            # keep track of words visited at this level of BFS
            visited_this_level = {}

            for i in range(n):
                word = q.popleft()

                for i in range(len(word)):
                    # for each pattern of the current word
                    pattern = word[:i] + Solution.WILDCARD + word[i+1:]

                    for next_word in adjacency_list[pattern]:
                        if next_word == endWord:
                            # we don't return immediately because other
                            # sequences might reach the endWord in the same
                            # BFS level
                            found = True
                        if next_word not in visited_tree:
                            if next_word not in visited_this_level:
                                visited_this_level[next_word] = [word]
                                # queue up next word iff we haven't visited it yet
                                # or already are planning to visit it
                                q.append(next_word)
                            else:
                                visited_this_level[next_word].append(word)

            # add all seen words at this level to the global visited tree
            visited_tree.update(visited_this_level)

        return visited_tree

    def getLadders(self,
                   beginWord: str,
                   endWord: str,
                   wordTree: Dict[str, List[str]]) -> List[List[str]]:
        """
        DFS traversal from endWord to beginWord in a given tree.
        """
        def dfs(node: str) -> List[List[str]]:
            if node == beginWord:
                return [[beginWord]]
            if node not in wordTree:
                return []

            res = []
            parents = wordTree[node]
            for parent in parents:
                res += dfs(parent)
            for r in res:
                r.append(node)
            return res

        return dfs(endWord)