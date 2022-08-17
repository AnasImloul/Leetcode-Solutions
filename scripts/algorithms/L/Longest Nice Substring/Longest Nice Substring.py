class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        def divcon(s):
		    # string with length 1 or less arent considered nice
            if len(s) < 2:
                return ""
            
            pivot = []
            # get every character that is not nice
            for i, ch in enumerate(s):
                if ch.isupper() and ch.lower() not in s:
                    pivot.append(i)
                if ch.islower() and ch.upper() not in s:
                    pivot.append(i)
			# if no such character return the string
            if not pivot:
                return s
			# divide the string in half excluding the char that makes the string not nice
            else:
                mid = (len(pivot)) // 2
                return max(divcon(s[:pivot[mid]]),divcon(s[pivot[mid]+1:]),key=len)
        
        return divcon(s)
