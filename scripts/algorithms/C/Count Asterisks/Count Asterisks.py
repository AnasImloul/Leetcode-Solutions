class Solution:
    def countAsterisks(self, s: str) -> int:
        lst=[] 
        for i in s: 
            if '|' not in lst: 
                lst.append(i) 
            elif '|' in lst and i=='|': 
                lst.pop() 
        return lst.count('*')
