class PeekingIterator:
  def __init__ (self,iterator):
    self.arr = iterator.v 
    self._next = 0 
    self.is_has_next = True 
  
  def next(self):
    val = self.arr[self._next] 
    self.next+=1 
    if self.next >= len(self.arr):
      self.is_has_next = False 
    return val 
  
  def hasNext(self):
    return self.is_has_next 
  
  def peek(self):
    return self.arr[self._next]
