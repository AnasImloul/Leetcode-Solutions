# Runtime: 0 ms (Top 100.00%) | Memory: 19.20 MB (Top 58.06%)

class Solution:
  def isReachable(self, targetX: int, targetY: int) -> bool:
    x = self.decrease(targetX)
    y = self.decrease(targetY)

    while True:
      if x == 1 or y == 1:
        return True

      if x == y:
        return False # The coordinates won't change, we are stuck

      newCoordinate = self.decrease(x + y)

      # Putting the new coordinate to the place of the biggest current coordinate
      if x < y:
        y = newCoordinate
      else:
        x = newCoordinate

  def decrease(self, value):
    while value % 2 == 0:
      value = value >> 1 # This means division by 2
    return value
