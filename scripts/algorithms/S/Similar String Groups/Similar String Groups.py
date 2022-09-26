# Runtime: 5068 ms (Top 15.23%) | Memory: 14.3 MB (Top 64.62%)
class Solution: #839. Similar String Groups
    def numSimilarGroups(self, strs: List[str]) -> int:
        #memo
        visited = set()
        count = 0
        for i in range(len(strs)):
            if i not in visited:
                #dfs
                self.dfs(strs, i, visited)
                #add a new connected area
                count += 1
        return count

    #dfs to search the similar string from 0 to n-1
    def dfs(self, strs, i, visited):
        #add current string to memo
        visited.add(i)
        for j in range(len(strs)):
            if self.isSimilar(strs[i], strs[j]) and j not in visited:
                self.dfs(strs, j , visited)

    # calculate the similarity of two strings
    def isSimilar(self, str1, str2):
        diff_count = 0
        for i in range(len(str1)):
            if str1[i] != str2[i]:
                diff_count += 1
        return diff_count <= 2