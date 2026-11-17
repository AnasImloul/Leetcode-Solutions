# Runtime: 100 ms (Top 61.76%) | Memory: 19.10 MB (Top 91.18%)

class Solution:

  def merge(self, s1, s2):
    if s2 in s1:
      return s1

    for i in range(len(s1)):
      if s2.startswith(s1[i:]):
        return s1[:i] + s2

    return s1 + s2

  def minimumString(self, a: str, b: str, c: str) -> str:
    res, l = '', float('inf')
    for s in [
      self.merge(self.merge(a, b), c),
      self.merge(self.merge(b, a), c),
      self.merge(self.merge(c, b), a),
      self.merge(self.merge(b, c), a),
      self.merge(self.merge(a, c), b),
      self.merge(self.merge(c, a), b),
    ]:
      if len(s) < l:
        res, l = s, len(s)
      elif len(s) == l:
        res = min(res, s)

    return res
