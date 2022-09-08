# Runtime: 266 ms (Top 32.10%) | Memory: 14.1 MB (Top 35.69%)
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        ans = 0
        count = [0]*26
        counts = []
        new_arr = []

        for string in arr:
            flag = True
            tmp = [0]*26
            for ch in string:
                if tmp[ord(ch) - 97] == True:
                    flag = False
                    break
                else:
                    tmp[ord(ch) - 97] = True

            if flag == False:continue
            counts.append(tmp)
            new_arr.append(string)

        n = len(new_arr)

        def compatible(a,b):
            for i in range(26):
                if a[i] == True and b[i] == True: return False
            return True

        def addUp(a,b):
            for i in range(26):
                if b[i] == True: a[i] = True

        def solve(index,count):
            if index == n:return 0
            cpy = count.copy()
            ch1 = -inf
            if compatible(count,counts[index]):
                addUp(count,counts[index])
                ch1 = solve(index+1,count) + len(new_arr[index])
            ch2 = solve(index+1 , cpy)
            ans = max(ch1,ch2)
            return ans

        return solve(0,count)