// Runtime: 3006 ms (Top 9.88%) | Memory: 71.00 MB (Top 5.13%)

class NumArray:

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.seg_tree = [dict() for _ in range(4*self.n)]
        
        def build(i, j, indx):
            self.seg_tree[indx]['left'] = i
            self.seg_tree[indx]['right'] = j
            
            if i == j:
                self.seg_tree[indx]['val'] = nums[i]
                return
            
            mid = (i+j)//2
            
            build(i, mid, 2*indx)
            build(mid+1, j, 2*indx+1)
            
            self.seg_tree[indx]['val'] =  self.seg_tree[2*indx]['val'] +self.seg_tree[2*indx+1]['val']
        
        build(0,self.n-1,1) # start the tree from index 1
        
        
                
    def update(self, index: int, val: int) -> None:
        
        def seg_update(index, val, indx):
            i = self.seg_tree[indx]['left']
            j = self.seg_tree[indx]['right']
            
            if i==j and i==index:
                self.seg_tree[indx]['val'] = val
                return
            
            mid = (i+j)//2
            
            if index<=mid:
                seg_update(index,val,2*indx)
                self.seg_tree[indx]['val'] =  self.seg_tree[2*indx]['val'] +self.seg_tree[2*indx+1]['val']
            else:
                seg_update(index,val,2*indx+1)
                self.seg_tree[indx]['val'] =  self.seg_tree[2*indx]['val'] +self.seg_tree[2*indx+1]['val']
        
        seg_update(index, val, 1)
        

    def sumRange(self, left: int, right: int) -> int:
        
        def query(left, right, indx):
            i = self.seg_tree[indx]['left']
            j = self.seg_tree[indx]['right']
            
            if i == left and j == right:
                return self.seg_tree[indx]['val']
            
            mid = (i+j)//2
            
            if i <= left and right <=mid:
                return query(left,right,2*indx)
            if mid+1<=left and right <= j:
                return query(left,right,2*indx+1)
            
            lval = query(left, mid, 2*indx)
            rval = query(mid+1, right, 2*indx+1)
            
            return lval + rval
        
        return query(left, right, 1)
