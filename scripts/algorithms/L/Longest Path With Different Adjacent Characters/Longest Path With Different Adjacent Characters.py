class Solution:
    def longestPath(self, parent: list[int], s: str) -> int:
        def l_path_and_chain(tree: dict[int, list[int]], s: str, root: int) -> tuple[int, int]:
            lp = lc1 = lc2 = 0
            for child, path, chain in ((c, *l_path_and_chain(tree, s, c)) for c in tree[root]):
                lp = max(lp, path)
                if s[child] != s[root]: *_, lc2, lc1 = sorted((chain, lc2, lc1))

            return max(lp, lc1 + lc2 + 1), lc1 + 1

        t = defaultdict(list)
        for c, p in enumerate(parent): t[p].append(c)
        return l_path_and_chain(t, s, 0)[0]
