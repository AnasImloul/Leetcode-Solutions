class Solution:
    def intersectionSizeTwo(self, A: List[List[int]]) -> int:
        A.sort(key=lambda x:(x[1],-x[0]))
        ans = []
        ans.append(A[0][1]-1)
        ans.append(A[0][1])
        n = len(A)
        # print(A)
        for i in range(1,n):
            if A[i][0]>ans[-1]:
                ans.append(A[i][1]-1)
                ans.append(A[i][1])
            elif A[i][0]>ans[-2]:
                ans.append(A[i][1])
        # print(ans)
        return len(ans)
