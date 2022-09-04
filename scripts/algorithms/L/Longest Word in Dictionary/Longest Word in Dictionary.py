# Runtime: 240 ms (Top 36.59%) | Memory: 15.2 MB (Top 46.59%)
class Solution:
    def longestWord(self, words: List[str]) -> str:
        TrieNode = lambda: defaultdict(TrieNode)
        root = TrieNode()
        for i,s in enumerate(words):
            cur = root
            for c in s: cur=cur[c]
            cur['$']=i

        ans = ''
        st = list(root.values())
        while st:
            cur = st.pop()
            if '$' in cur:
                w = words[cur['$']]
                if len(ans)<len(w) or len(ans)==len(w) and w<ans:ans=w
                st.extend([cur[i] for i in cur if i!='$'])
        return ans