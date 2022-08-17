class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        ans = []
        d = {(i[0],i[1]) : True for i in queens}
        def goUp(r,c):
            while r >=0:
                if (r,c) in d:
                    ans.append([r,c])
                    break
                r -= 1
        def goDown(r,c):
            while r < 8:
                if (r,c) in d: 
                    ans.append([r,c])
                    break
                r += 1
        def goLeft(r,c):
            while c >= 0:
                if (r,c) in d:
                    ans.append([r,c])
                    break
                c -= 1
        def goRight(r,c):
            while c < 8:
                if (r,c) in d: 
                    ans.append([r,c])
                    break
                c += 1
        def goD1(r,c):
            while r >=0 and c >= 0:
                if (r,c) in d:
                    ans.append([r,c])
                    break
                r -= 1
                c -= 1
        def goD2(r,c):
            while r < 8 and c >= 0:
                if (r,c) in d: 
                    ans.append([r,c])
                    break
                r += 1
                c -= 1
        def goD3(r,c):
            while r < 8 and c < 8:
                if (r,c) in d: 
                    ans.append([r,c])
                    break
                r += 1
                c += 1
        def goD4(r,c):
            while r >= 0 and c < 8:
                if (r,c) in d: 
                    ans.append([r,c])
                    break
                r -= 1
                c += 1

        goUp(king[0],king[1])
        goDown(king[0],king[1])
        goLeft(king[0],king[1])
        goRight(king[0],king[1])
        goD1(king[0],king[1])
        goD2(king[0],king[1])
        goD3(king[0],king[1])
        goD4(king[0],king[1])

        return ans
