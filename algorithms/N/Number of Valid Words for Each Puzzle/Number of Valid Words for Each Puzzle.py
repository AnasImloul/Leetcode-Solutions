class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        look_up=collections.defaultdict(int)
        def get_mask(word):
            mask=0
            for c in word:
                mask |= 1<<(ord(c)-ord('a'))
            return mask
        for word in words:
            mask=get_mask(word)
            look_up[mask]+=1
        ans=[]
        def solve(puzzle_idx,mask,c_idx):
            if c_idx==len(puzzles[puzzle_idx]):
                ans[-1]+=look_up[mask]
                return
            #take this c_idx
            solve(puzzle_idx,mask | 1<<(ord(puzzles[puzzle_idx][c_idx])-ord('a')),c_idx+1)
            #dont take this c_idx
            solve(puzzle_idx,mask,c_idx+1)
        for i,puzzle in enumerate(puzzles):
            ans.append(0)
            solve(i,1<<(ord(puzzle[0])-ord('a')),1)
        return ans
