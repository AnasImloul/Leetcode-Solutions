# Runtime: 69 ms (Top 20.00%) | Memory: 13.9 MB (Top 79.88%)

class Solution:

    def assign_sign(self, sign):
      # verify that we haven't already got a sign
      #&nbsp;"+42-" -> we don't want to return -42; hence check
      if not self.is_neg and not self.is_pos:
          # no sign has been set yet
        if sign=="+":
          self.is_pos = True
        elif sign=="-":
          self.is_neg = True
      return

    def add_to_int(self, num):
      if not self.num:
        self.num = num
      else:
        self.num = (self.num*10) + num

    def myAtoi(self, s: str) -> int:
        #&nbsp;remove the leading and trailing spaces
        self.is_neg = False
        self.is_pos = False
        self.num = None
        s=s.strip()
        for i in s:
          # ignore the rest of the string if a non digit character is read
          if i in ("+","-"):
            #&nbsp;only read the first symbol; break if second symbol is read
            if self.is_pos or self.is_neg or isinstance(self.num, int):
              #&nbsp;one of the two symbols is read or a number is read
              break
            self.assign_sign(i)
            continue
          try:
            i = int(i)
            self.add_to_int(i)
          except ValueError:
            # it's neither a sign, nor a number; terminate
            break

        # outside the loop; compile the result
        if not self.num:
          return 0
        upper_limit = 2**31 - 1
        if self.is_pos or (not self.is_pos and not self.is_neg):
          if self.num > upper_limit:
            self.num = upper_limit
        elif self.is_neg:
          if self.num > upper_limit+1:
            self.num = upper_limit+1
          self.num = -1 * self.num
        return self.num
