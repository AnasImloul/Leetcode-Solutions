class Solution:
    def numSpecialEquivGroups(self, words) -> int:
        return len(set([(''.join(sorted(i[::2])),''.join(sorted(i[1::2]))) for i in words]))