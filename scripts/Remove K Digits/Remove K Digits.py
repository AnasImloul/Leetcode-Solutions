# Lets make monotonically growing stack and save the indexes of popped elements into deletes dict.
#as soon as len(delete) == k delete those indexes from the initial string and thats the answer.
#if len(delete) < k remove k-len(delete) chars from right and thats the answer
class Solution:
    def removeKdigits(self, s: str, k: int) -> str:
        if len(s) == k:
            return '0'
        stack = []
        delete = {}
        for i in range(len(s)):

            while stack and s[i] < stack[-1][0]:
                delete[stack.pop()[1]] = 1
                if len(delete) == k:
                    break
            if len(delete) == k:
                return self.deleteindexes(s, delete, k)
            stack.append([s[i], i])
        s1 = self.deleteindexes(s, delete, k)

        return str(int(s1[:len(s1)-k +len(delete)]))


    def deleteindexes(self, s, delete, k):
        if not delete:
            return s
        if len(delete) == k:
            return str(int(''.join([c for ind, c in enumerate(s) if ind not in delete])))
        else:
            return ''.join([c for ind, c in enumerate(s) if ind not in delete])


