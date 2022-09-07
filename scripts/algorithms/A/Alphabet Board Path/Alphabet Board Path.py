# Runtime: 68 ms (Top 16.25%) | Memory: 14 MB (Top 13.50%)
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        def shortestPath(r,c,tr,tc):
            path = ""
            pr = r
            while r > tr:
                path += 'U'
                r -= 1
            while r < tr:
                path += 'D'
                r += 1
            if tr == 5 and pr != tr: path = path[:len(path) - 1]
            while c > tc:
                path += 'L'
                c -= 1
            while c < tc:
                path += 'R'
                c += 1
            if tr == 5 and pr != tr: path = path + 'D'
            return path

        table = ['abcde','fghij','klmno','pqrst','uvwxy','z']
        r,c = 0,0
        ans = ""
        for character in target:
            t_row = None
            for i,word in enumerate(table):
                if character in word:
                    t_row = i
                    break
            t_col = table[i].index(character)
            ans += shortestPath(r,c,t_row,t_col) + '!'
            r,c = t_row,t_col
        return ans