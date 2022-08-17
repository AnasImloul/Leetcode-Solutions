class Solution:
    def recursion(self, idx , n , height , width):
        if idx == n:return height
        
        if (idx,height,width) in self.dp: return self.dp[(idx,height,width)]
        
        choice1 = self.recursion(idx+1,n,max(self.books[idx][1],height), width - self.books[idx][0])\
        if width >= self.books[idx][0] else float('inf')
        
        choice2 = self.recursion(idx+1,n,self.books[idx][1], self.shelfWidth - self.books[idx][0]) + height
        
        ans = min(choice1,choice2)
        self.dp[(idx,height,width)] = ans
        return ans
    
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        self.books = books
        self.shelfWidth = shelfWidth
        self.dp = {}
        return self.recursion(0,len(books),0,shelfWidth)
